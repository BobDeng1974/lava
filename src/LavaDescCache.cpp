// The MIT License
// Copyright (c) 2018 Philip Rideout

#include <par/LavaLoader.h>
#include <par/LavaDescCache.h>
#include <par/LavaLog.h>

#include <unordered_map>

#include <assert.h>

#include "LavaInternal.h"

using namespace std;

namespace par {
namespace {

// Maximum number of descriptor sets that can be allocated in each descriptor pool.
constexpr uint32_t MAX_NUM_DESCRIPTORS = 1000;

struct CacheKey {
    vector<VkBuffer> uniformBuffers;
    vector<VkDescriptorImageInfo> imageSamplers;
    vector<VkDescriptorImageInfo> inputAttachments;
};

struct CacheVal {
    VkDescriptorSet handle;
    uint64_t timestamp;
    // move-only (disallow copy) to allow keeping a pointer to a value in the map.
    CacheVal(CacheVal const&) = delete;
    CacheVal& operator=(CacheVal const&) = delete;
    CacheVal(CacheVal &&) = default;
    CacheVal& operator=(CacheVal &&) = default;
};

struct IsEqual {
    bool operator()(const VkDescriptorImageInfo& a, const VkDescriptorImageInfo& b) const {
        return a.sampler == b.sampler && a.imageView == b.imageView &&
                a.imageLayout == b.imageLayout;
    }
    bool operator()(const CacheKey& a, const CacheKey& b) const {
        if (a.uniformBuffers.size() != b.uniformBuffers.size()) {
            return false;
        }
        for (size_t i = 0; i < a.uniformBuffers.size(); ++i) {
            if (a.uniformBuffers[i] != b.uniformBuffers[i]) {
                return false;
            }
        }
        if (a.imageSamplers.size() != b.imageSamplers.size()) {
            return false;
        }
        for (size_t i = 0; i < a.imageSamplers.size(); ++i) {
            if (!(*this)(a.imageSamplers[i], b.imageSamplers[i])) {
                return false;
            }
        }
        if (a.inputAttachments.size() != b.inputAttachments.size()) {
            return false;
        }
        for (size_t i = 0; i < a.inputAttachments.size(); ++i) {
            if (!(*this)(a.inputAttachments[i], b.inputAttachments[i])) {
                return false;
            }
        }
        return true;
    }
};

struct HashFn {
    uint64_t operator()(const CacheKey& key) const {
        uint64_t ubhash = 0;
        if (key.uniformBuffers.size()) {
            size_t ubsize = key.uniformBuffers.size() * sizeof(key.uniformBuffers[0]);
            assert(0 == (ubsize & 3) && "Hashing requires a size that is a multiple of 4.");
            ubhash = murmurHash((uint32_t*) key.uniformBuffers.data(), ubsize / 4, 0u);
        }
        uint64_t ishash = 0;
        if (key.imageSamplers.size()) {
            size_t issize = key.imageSamplers.size() * sizeof(key.imageSamplers[0]);
            assert(0 == (issize & 3) && "Hashing requires a size that is a multiple of 4.");
            ishash = murmurHash((uint32_t*) key.imageSamplers.data(), issize / 4, 0u);
        }
        if (key.inputAttachments.size()) {
            size_t issize = key.inputAttachments.size() * sizeof(key.inputAttachments[0]);
            assert(0 == (issize & 3) && "Hashing requires a size that is a multiple of 4.");
            ishash = murmurHash((uint32_t*) key.inputAttachments.data(), issize / 4, ishash);
        }
        return ubhash | (ishash << 32);
    }
};

using Cache = unordered_map<CacheKey, CacheVal, HashFn, IsEqual>;

namespace DirtyFlag {
    static constexpr uint8_t UNIFORM_BUFFER = 1 << 0; 
    static constexpr uint8_t IMAGE_SAMPLER = 1 << 1;
    static constexpr uint8_t INPUT_ATTACHMENT = 1 << 2;
}

struct LavaDescCacheImpl : LavaDescCache {
    ~LavaDescCacheImpl() noexcept;
    CacheVal* currentDescriptor = nullptr;
    VkDevice device;
    Cache cache;
    CacheKey currentState;
    uint8_t dirtyFlags = 0xf;
    VkDescriptorSetLayout layout;
    VkDescriptorPool descriptorPool;
    uint32_t numUniformBuffers;
    uint32_t numImageSamplers;
    uint32_t numInputAttachments;
    std::vector<VkWriteDescriptorSet> writes;
    std::vector<VkDescriptorBufferInfo> bufferWrites;
    std::vector<VkDescriptorImageInfo> imageWrites;
};

LAVA_DEFINE_UPCAST(LavaDescCache)

} // anonymous namespace

LavaDescCache* LavaDescCache::create(Config config) noexcept {
    assert(config.device);
    auto impl = new LavaDescCacheImpl;
    impl->device = config.device;
    impl->currentState = {
        .uniformBuffers = config.uniformBuffers,
        .imageSamplers = config.imageSamplers,
        .inputAttachments = config.inputAttachments,
    };
    impl->numUniformBuffers = (uint32_t) config.uniformBuffers.size();
    impl->numImageSamplers = (uint32_t) config.imageSamplers.size();
    impl->numInputAttachments = (uint32_t) config.inputAttachments.size();
    impl->bufferWrites.resize(impl->numUniformBuffers);
    impl->imageWrites.resize(impl->numImageSamplers + impl->numInputAttachments);
    impl->writes.resize(impl->bufferWrites.size() + impl->imageWrites.size());

    vector<VkDescriptorSetLayoutBinding> bindings;
    bindings.reserve(impl->writes.size());
    uint32_t binding = 0;
    for (auto dummy LAVA_UNUSED : config.uniformBuffers) {
        bindings.emplace_back(VkDescriptorSetLayoutBinding {
            .binding = binding++,
            .descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
            .descriptorCount = 1,
            .stageFlags = VK_SHADER_STAGE_ALL,
        });
    }
    for (auto dummy LAVA_UNUSED : config.imageSamplers) {
        bindings.emplace_back(VkDescriptorSetLayoutBinding {
            .binding = binding++,
            .descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,
            .descriptorCount = 1,
            .stageFlags = VK_SHADER_STAGE_ALL,
        });
    }
    for (auto dummy LAVA_UNUSED : config.inputAttachments) {
        bindings.emplace_back(VkDescriptorSetLayoutBinding {
            .binding = binding++,
            .descriptorType = VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT,
            .descriptorCount = 1,
            .stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT,
        });
    }

    VkDescriptorSetLayoutCreateInfo info {
        .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
        .bindingCount = (uint32_t) bindings.size(),
        .pBindings = bindings.data()
    };
    vkCreateDescriptorSetLayout(impl->device, &info, VKALLOC, &impl->layout);

    VkDescriptorPoolSize poolSizes[3] = {};
    VkDescriptorPoolCreateInfo poolInfo {
        .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO,
        .pPoolSizes = poolSizes,
        .maxSets = MAX_NUM_DESCRIPTORS,
        .flags = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT
    };
    if (impl->numUniformBuffers > 0) {
        VkDescriptorPoolSize* size = &poolSizes[poolInfo.poolSizeCount++];
        size->type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        size->descriptorCount = poolInfo.maxSets * impl->numUniformBuffers;
    }
    if (impl->numImageSamplers > 0) {
        VkDescriptorPoolSize* size = &poolSizes[poolInfo.poolSizeCount++];
        size->type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        size->descriptorCount = poolInfo.maxSets * impl->numImageSamplers;
    }
    if (impl->numInputAttachments > 0) {
        VkDescriptorPoolSize* size = &poolSizes[poolInfo.poolSizeCount++];
        size->type = VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT;
        size->descriptorCount = poolInfo.maxSets * impl->numInputAttachments;
    }
    assert(poolInfo.poolSizeCount > 0);
    vkCreateDescriptorPool(impl->device, &poolInfo, VKALLOC, &impl->descriptorPool);

    return impl;
}

void LavaDescCache::operator delete(void* ptr) {
    auto impl = (LavaDescCacheImpl*) ptr;
    ::delete impl;
}

LavaDescCacheImpl::~LavaDescCacheImpl() noexcept {
    for (auto& pair : cache) {
        vkFreeDescriptorSets(device, descriptorPool, 1, &pair.second.handle);
    }
    vkDestroyDescriptorPool(device, descriptorPool, VKALLOC);
    vkDestroyDescriptorSetLayout(device, layout, VKALLOC);
}

VkDescriptorSetLayout LavaDescCache::getLayout() const noexcept {
    return upcast(this)->layout;
}

bool LavaDescCache::getDescriptorSet(VkDescriptorSet* descriptorSet,
        vector<VkWriteDescriptorSet>* writes) noexcept {
    LavaDescCacheImpl& impl = *upcast(this);
    if (!impl.dirtyFlags) {
        impl.currentDescriptor->timestamp = getCurrentTime();
        *descriptorSet = impl.currentDescriptor->handle;
        return false;
    }
    impl.dirtyFlags = 0;
    auto iter = impl.cache.find(impl.currentState);
    if (iter != impl.cache.end()) {
        impl.currentDescriptor = &(iter->second);
        impl.currentDescriptor->timestamp = getCurrentTime();
        *descriptorSet = impl.currentDescriptor->handle;
        return true;
    }

    VkDescriptorSetAllocateInfo allocInfo {
        .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO,
        .descriptorPool = impl.descriptorPool,
        .descriptorSetCount = 1,
        .pSetLayouts = &impl.layout
    };
    vkAllocateDescriptorSets(impl.device, &allocInfo, descriptorSet);

    auto& key = impl.currentState;
    VkWriteDescriptorSet* pWrite = impl.writes.data();
    VkDescriptorBufferInfo* pBufferWrite = impl.bufferWrites.data();
    uint32_t binding = 0;
    for (VkBuffer buffer : key.uniformBuffers) {
        if (buffer == VK_NULL_HANDLE) {
            binding++;
            continue;
        }
        *pWrite++ = {
            .sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            .dstSet = *descriptorSet,
            .dstBinding = binding++,
            .descriptorCount = 1,
            .descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
            .pBufferInfo = pBufferWrite
        };
        *pBufferWrite++ = {
            .buffer = buffer,
            .offset = 0,
            .range = VK_WHOLE_SIZE
        };
    }
    VkDescriptorImageInfo* pInfoWrite = impl.imageWrites.data();
    for (VkDescriptorImageInfo info : key.imageSamplers) {
        if (info.sampler == VK_NULL_HANDLE) {
            binding++;
            continue;
        }
        *pWrite++ = {
            .sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            .dstSet = *descriptorSet,
            .dstBinding = binding++,
            .descriptorCount = 1,
            .descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,
            .pImageInfo = pInfoWrite
        };
        *pInfoWrite++ = info;
    }
    for (VkDescriptorImageInfo info : key.inputAttachments) {
        if (info.sampler == VK_NULL_HANDLE) {
            binding++;
            continue;
        }
        *pWrite++ = {
            .sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            .dstSet = *descriptorSet,
            .dstBinding = binding++,
            .descriptorCount = 1,
            .descriptorType = VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT,
            .pImageInfo = pInfoWrite
        };
        *pInfoWrite++ = info;
    }

    const size_t nwrites = pWrite - impl.writes.data();
    if (writes) {
        *writes = impl.writes;
        writes->resize(nwrites);
    } else {
        vkUpdateDescriptorSets(impl.device, nwrites, impl.writes.data(), 0, nullptr);
    }

    const size_t size0 = impl.cache.size();
    iter = impl.cache.emplace(make_pair(impl.currentState, CacheVal {
        *descriptorSet, getCurrentTime() })).first;
    const size_t size1 = impl.cache.size();
    LOG_CHECK(size1 > size0, "Hash error.");

    impl.currentDescriptor = &(iter->second);
    return nwrites > 0;
}

VkDescriptorSet LavaDescCache::getDescriptor() noexcept {
    VkDescriptorSet handle;
    getDescriptorSet(&handle, nullptr);
    return handle;
}

VkDescriptorSet* LavaDescCache::getDescPointer() noexcept {
    LavaDescCacheImpl* impl = upcast(this);
    getDescriptor();
    CacheVal* mapval = impl->currentDescriptor;
    return mapval ? &mapval->handle : nullptr;
}

void LavaDescCache::setUniformBuffer(uint32_t bindingIndex, VkBuffer uniformBuffer) noexcept {
    LavaDescCacheImpl* impl = upcast(this);
    LOG_CHECK(bindingIndex < impl->numUniformBuffers, "Uniform binding out of range.");
    auto& buffers = impl->currentState.uniformBuffers;
    assert(bindingIndex < buffers.size());
    if (buffers[bindingIndex] != uniformBuffer) {
        impl->dirtyFlags |= DirtyFlag::UNIFORM_BUFFER;
        buffers[bindingIndex] = uniformBuffer;
    }
}

void LavaDescCache::setImageSampler(uint32_t bindingIndex, VkDescriptorImageInfo binding) noexcept {
    LavaDescCacheImpl* impl = upcast(this);
    LOG_CHECK(bindingIndex >= impl->numUniformBuffers &&
            bindingIndex < impl->numUniformBuffers + impl->numImageSamplers,
            "Sampler binding out of range.");
    bindingIndex -= impl->numUniformBuffers;
    auto& imageSamplers = impl->currentState.imageSamplers;
    assert(bindingIndex < imageSamplers.size());
    if (!IsEqual()(imageSamplers[bindingIndex], binding)) {
        impl->dirtyFlags |= DirtyFlag::IMAGE_SAMPLER;
        imageSamplers[bindingIndex] = binding;
    }
}

void LavaDescCache::setInputAttachment(uint32_t bindingIndex, VkDescriptorImageInfo binding) noexcept {
    LavaDescCacheImpl* impl = upcast(this);
    LOG_CHECK(bindingIndex >= impl->numUniformBuffers + impl->numImageSamplers &&
            bindingIndex < impl->writes.size(), "Attachment binding out of range.");
    bindingIndex -= (impl->numUniformBuffers + impl->numImageSamplers);
    auto& inputAttachments = impl->currentState.inputAttachments;
    assert(bindingIndex < inputAttachments.size());
    if (!IsEqual()(inputAttachments[bindingIndex], binding)) {
        impl->dirtyFlags |= DirtyFlag::INPUT_ATTACHMENT;
        inputAttachments[bindingIndex] = binding;
    }
}

void LavaDescCache::releaseUnused(uint64_t milliseconds) noexcept {
    LavaDescCacheImpl* impl = upcast(this);
    const uint64_t expiration = getCurrentTime() - milliseconds;
    auto& cache = impl->cache;
    for (decltype(impl->cache)::const_iterator iter = cache.begin(); iter != cache.end();) {
        if (iter->second.timestamp < expiration) {
            vkFreeDescriptorSets(impl->device, impl->descriptorPool, 1, &iter->second.handle);
            iter = cache.erase(iter);
        } else {
            ++iter;
        }
    }
}

void LavaDescCache::unsetUniformBuffer(VkBuffer uniformBuffer) noexcept {
    LavaDescCacheImpl* impl = upcast(this);
    for (auto& el : impl->currentState.uniformBuffers) {
        if (el == uniformBuffer) {
            impl->dirtyFlags |= DirtyFlag::UNIFORM_BUFFER;
            el = VK_NULL_HANDLE;
        }
    }
}

void LavaDescCache::unsetImageSampler(VkDescriptorImageInfo binding) noexcept {
    LavaDescCacheImpl* impl = upcast(this);
    for (auto& el : impl->currentState.imageSamplers) {
        if (IsEqual()(el, binding)) {
            impl->dirtyFlags |= DirtyFlag::IMAGE_SAMPLER;
            el = {};
        }
    }
}

void LavaDescCache::unsetInputAttachment(VkDescriptorImageInfo binding) noexcept {
    LavaDescCacheImpl* impl = upcast(this);
    for (auto& el : impl->currentState.inputAttachments) {
        if (IsEqual()(el, binding)) {
            impl->dirtyFlags |= DirtyFlag::INPUT_ATTACHMENT;
            el = {};
        }
    }
}

} // par namespace