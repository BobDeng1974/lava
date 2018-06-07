// The MIT License
// Copyright (c) 2018 Philip Rideout

#pragma once

#include <vulkan/vulkan.h>

namespace par {

class LavaCpuBuffer {
public:
    struct Config {
        VkDevice device;
        VkPhysicalDevice gpu;
        uint32_t size;
        void const* source; // if non-null, triggers a memcpy during construction
        VkBufferUsageFlags usage;
    };    
    static LavaCpuBuffer* create(Config config) noexcept;
    ~LavaCpuBuffer() noexcept;
    VkBuffer getBuffer() const noexcept;
    void setData(void const* sourceData, uint32_t bytesToCopy) noexcept;
protected:
    LavaCpuBuffer() noexcept = default;
    // par::noncopyable
    LavaCpuBuffer(LavaCpuBuffer const&) = delete;
    LavaCpuBuffer& operator=(LavaCpuBuffer const&) = delete;
};

}
