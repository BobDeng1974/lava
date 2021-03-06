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
        uint32_t size;      // Size of the upload in bytes.
        uint32_t capacity;  // Optional capacity, must be 0 or greater than "size".
        void const* source; // if non-null, triggers a memcpy during construction
        VkBufferUsageFlags usage;
    };    
    static LavaCpuBuffer* create(Config config) noexcept;
    static void operator delete(void* );
    VkBuffer getBuffer() const noexcept;
    void setData(void const* sourceData, uint32_t bytesToCopy,
            uint32_t offset = 0) noexcept;
    uint8_t* map() const noexcept;
    void unmap() const noexcept;
protected:
    LavaCpuBuffer() noexcept = default;
    LavaCpuBuffer(LavaCpuBuffer const&) = delete;
    LavaCpuBuffer& operator=(LavaCpuBuffer const&) = delete;
};

}
