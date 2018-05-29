#pragma once

#if defined(VULKAN_H_) && !defined(VK_NO_PROTOTYPES)
#error Please do not include vulkan.h when using LavaLoader
#endif

#ifndef VULKAN_H_
    #ifndef VK_NO_PROTOTYPES
    #define VK_NO_PROTOTYPES
    #endif
    #include <vulkan/vulkan.h>
#endif

#if defined(VK_VERSION_1_0)
extern PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers;
extern PFN_vkAllocateDescriptorSets vkAllocateDescriptorSets;
extern PFN_vkAllocateMemory vkAllocateMemory;
extern PFN_vkBeginCommandBuffer vkBeginCommandBuffer;
extern PFN_vkBindBufferMemory vkBindBufferMemory;
extern PFN_vkBindImageMemory vkBindImageMemory;
extern PFN_vkCmdBeginQuery vkCmdBeginQuery;
extern PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass;
extern PFN_vkCmdBindDescriptorSets vkCmdBindDescriptorSets;
extern PFN_vkCmdBindIndexBuffer vkCmdBindIndexBuffer;
extern PFN_vkCmdBindPipeline vkCmdBindPipeline;
extern PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers;
extern PFN_vkCmdBlitImage vkCmdBlitImage;
extern PFN_vkCmdClearAttachments vkCmdClearAttachments;
extern PFN_vkCmdClearColorImage vkCmdClearColorImage;
extern PFN_vkCmdClearDepthStencilImage vkCmdClearDepthStencilImage;
extern PFN_vkCmdCopyBuffer vkCmdCopyBuffer;
extern PFN_vkCmdCopyBufferToImage vkCmdCopyBufferToImage;
extern PFN_vkCmdCopyImage vkCmdCopyImage;
extern PFN_vkCmdCopyImageToBuffer vkCmdCopyImageToBuffer;
extern PFN_vkCmdCopyQueryPoolResults vkCmdCopyQueryPoolResults;
extern PFN_vkCmdDispatch vkCmdDispatch;
extern PFN_vkCmdDispatchIndirect vkCmdDispatchIndirect;
extern PFN_vkCmdDraw vkCmdDraw;
extern PFN_vkCmdDrawIndexed vkCmdDrawIndexed;
extern PFN_vkCmdDrawIndexedIndirect vkCmdDrawIndexedIndirect;
extern PFN_vkCmdDrawIndirect vkCmdDrawIndirect;
extern PFN_vkCmdEndQuery vkCmdEndQuery;
extern PFN_vkCmdEndRenderPass vkCmdEndRenderPass;
extern PFN_vkCmdExecuteCommands vkCmdExecuteCommands;
extern PFN_vkCmdFillBuffer vkCmdFillBuffer;
extern PFN_vkCmdNextSubpass vkCmdNextSubpass;
extern PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier;
extern PFN_vkCmdPushConstants vkCmdPushConstants;
extern PFN_vkCmdResetEvent vkCmdResetEvent;
extern PFN_vkCmdResetQueryPool vkCmdResetQueryPool;
extern PFN_vkCmdResolveImage vkCmdResolveImage;
extern PFN_vkCmdSetBlendConstants vkCmdSetBlendConstants;
extern PFN_vkCmdSetDepthBias vkCmdSetDepthBias;
extern PFN_vkCmdSetDepthBounds vkCmdSetDepthBounds;
extern PFN_vkCmdSetEvent vkCmdSetEvent;
extern PFN_vkCmdSetLineWidth vkCmdSetLineWidth;
extern PFN_vkCmdSetScissor vkCmdSetScissor;
extern PFN_vkCmdSetStencilCompareMask vkCmdSetStencilCompareMask;
extern PFN_vkCmdSetStencilReference vkCmdSetStencilReference;
extern PFN_vkCmdSetStencilWriteMask vkCmdSetStencilWriteMask;
extern PFN_vkCmdSetViewport vkCmdSetViewport;
extern PFN_vkCmdUpdateBuffer vkCmdUpdateBuffer;
extern PFN_vkCmdWaitEvents vkCmdWaitEvents;
extern PFN_vkCmdWriteTimestamp vkCmdWriteTimestamp;
extern PFN_vkCreateBuffer vkCreateBuffer;
extern PFN_vkCreateBufferView vkCreateBufferView;
extern PFN_vkCreateCommandPool vkCreateCommandPool;
extern PFN_vkCreateComputePipelines vkCreateComputePipelines;
extern PFN_vkCreateDescriptorPool vkCreateDescriptorPool;
extern PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout;
extern PFN_vkCreateDevice vkCreateDevice;
extern PFN_vkCreateEvent vkCreateEvent;
extern PFN_vkCreateFence vkCreateFence;
extern PFN_vkCreateFramebuffer vkCreateFramebuffer;
extern PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines;
extern PFN_vkCreateImage vkCreateImage;
extern PFN_vkCreateImageView vkCreateImageView;
extern PFN_vkCreateInstance vkCreateInstance;
extern PFN_vkCreatePipelineCache vkCreatePipelineCache;
extern PFN_vkCreatePipelineLayout vkCreatePipelineLayout;
extern PFN_vkCreateQueryPool vkCreateQueryPool;
extern PFN_vkCreateRenderPass vkCreateRenderPass;
extern PFN_vkCreateSampler vkCreateSampler;
extern PFN_vkCreateSemaphore vkCreateSemaphore;
extern PFN_vkCreateShaderModule vkCreateShaderModule;
extern PFN_vkDestroyBuffer vkDestroyBuffer;
extern PFN_vkDestroyBufferView vkDestroyBufferView;
extern PFN_vkDestroyCommandPool vkDestroyCommandPool;
extern PFN_vkDestroyDescriptorPool vkDestroyDescriptorPool;
extern PFN_vkDestroyDescriptorSetLayout vkDestroyDescriptorSetLayout;
extern PFN_vkDestroyDevice vkDestroyDevice;
extern PFN_vkDestroyEvent vkDestroyEvent;
extern PFN_vkDestroyFence vkDestroyFence;
extern PFN_vkDestroyFramebuffer vkDestroyFramebuffer;
extern PFN_vkDestroyImage vkDestroyImage;
extern PFN_vkDestroyImageView vkDestroyImageView;
extern PFN_vkDestroyInstance vkDestroyInstance;
extern PFN_vkDestroyPipeline vkDestroyPipeline;
extern PFN_vkDestroyPipelineCache vkDestroyPipelineCache;
extern PFN_vkDestroyPipelineLayout vkDestroyPipelineLayout;
extern PFN_vkDestroyQueryPool vkDestroyQueryPool;
extern PFN_vkDestroyRenderPass vkDestroyRenderPass;
extern PFN_vkDestroySampler vkDestroySampler;
extern PFN_vkDestroySemaphore vkDestroySemaphore;
extern PFN_vkDestroyShaderModule vkDestroyShaderModule;
extern PFN_vkDeviceWaitIdle vkDeviceWaitIdle;
extern PFN_vkEndCommandBuffer vkEndCommandBuffer;
extern PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
extern PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties;
extern PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
extern PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
extern PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
extern PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges;
extern PFN_vkFreeCommandBuffers vkFreeCommandBuffers;
extern PFN_vkFreeDescriptorSets vkFreeDescriptorSets;
extern PFN_vkFreeMemory vkFreeMemory;
extern PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements;
extern PFN_vkGetDeviceMemoryCommitment vkGetDeviceMemoryCommitment;
extern PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
extern PFN_vkGetDeviceQueue vkGetDeviceQueue;
extern PFN_vkGetEventStatus vkGetEventStatus;
extern PFN_vkGetFenceStatus vkGetFenceStatus;
extern PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements;
extern PFN_vkGetImageSparseMemoryRequirements vkGetImageSparseMemoryRequirements;
extern PFN_vkGetImageSubresourceLayout vkGetImageSubresourceLayout;
extern PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
extern PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
extern PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
extern PFN_vkGetPhysicalDeviceImageFormatProperties vkGetPhysicalDeviceImageFormatProperties;
extern PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
extern PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
extern PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
extern PFN_vkGetPhysicalDeviceSparseImageFormatProperties vkGetPhysicalDeviceSparseImageFormatProperties;
extern PFN_vkGetPipelineCacheData vkGetPipelineCacheData;
extern PFN_vkGetQueryPoolResults vkGetQueryPoolResults;
extern PFN_vkGetRenderAreaGranularity vkGetRenderAreaGranularity;
extern PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges;
extern PFN_vkMapMemory vkMapMemory;
extern PFN_vkMergePipelineCaches vkMergePipelineCaches;
extern PFN_vkQueueBindSparse vkQueueBindSparse;
extern PFN_vkQueueSubmit vkQueueSubmit;
extern PFN_vkQueueWaitIdle vkQueueWaitIdle;
extern PFN_vkResetCommandBuffer vkResetCommandBuffer;
extern PFN_vkResetCommandPool vkResetCommandPool;
extern PFN_vkResetDescriptorPool vkResetDescriptorPool;
extern PFN_vkResetEvent vkResetEvent;
extern PFN_vkResetFences vkResetFences;
extern PFN_vkSetEvent vkSetEvent;
extern PFN_vkUnmapMemory vkUnmapMemory;
extern PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets;
extern PFN_vkWaitForFences vkWaitForFences;
#endif // defined(VK_VERSION_1_0)
#if defined(VK_VERSION_1_1)
extern PFN_vkBindBufferMemory2 vkBindBufferMemory2;
extern PFN_vkBindImageMemory2 vkBindImageMemory2;
extern PFN_vkCmdDispatchBase vkCmdDispatchBase;
extern PFN_vkCmdSetDeviceMask vkCmdSetDeviceMask;
extern PFN_vkCreateDescriptorUpdateTemplate vkCreateDescriptorUpdateTemplate;
extern PFN_vkCreateSamplerYcbcrConversion vkCreateSamplerYcbcrConversion;
extern PFN_vkDestroyDescriptorUpdateTemplate vkDestroyDescriptorUpdateTemplate;
extern PFN_vkDestroySamplerYcbcrConversion vkDestroySamplerYcbcrConversion;
extern PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion;
extern PFN_vkEnumeratePhysicalDeviceGroups vkEnumeratePhysicalDeviceGroups;
extern PFN_vkGetBufferMemoryRequirements2 vkGetBufferMemoryRequirements2;
extern PFN_vkGetDescriptorSetLayoutSupport vkGetDescriptorSetLayoutSupport;
extern PFN_vkGetDeviceGroupPeerMemoryFeatures vkGetDeviceGroupPeerMemoryFeatures;
extern PFN_vkGetDeviceQueue2 vkGetDeviceQueue2;
extern PFN_vkGetImageMemoryRequirements2 vkGetImageMemoryRequirements2;
extern PFN_vkGetImageSparseMemoryRequirements2 vkGetImageSparseMemoryRequirements2;
extern PFN_vkGetPhysicalDeviceExternalBufferProperties vkGetPhysicalDeviceExternalBufferProperties;
extern PFN_vkGetPhysicalDeviceExternalFenceProperties vkGetPhysicalDeviceExternalFenceProperties;
extern PFN_vkGetPhysicalDeviceExternalSemaphoreProperties vkGetPhysicalDeviceExternalSemaphoreProperties;
extern PFN_vkGetPhysicalDeviceFeatures2 vkGetPhysicalDeviceFeatures2;
extern PFN_vkGetPhysicalDeviceFormatProperties2 vkGetPhysicalDeviceFormatProperties2;
extern PFN_vkGetPhysicalDeviceImageFormatProperties2 vkGetPhysicalDeviceImageFormatProperties2;
extern PFN_vkGetPhysicalDeviceMemoryProperties2 vkGetPhysicalDeviceMemoryProperties2;
extern PFN_vkGetPhysicalDeviceProperties2 vkGetPhysicalDeviceProperties2;
extern PFN_vkGetPhysicalDeviceQueueFamilyProperties2 vkGetPhysicalDeviceQueueFamilyProperties2;
extern PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 vkGetPhysicalDeviceSparseImageFormatProperties2;
extern PFN_vkTrimCommandPool vkTrimCommandPool;
extern PFN_vkUpdateDescriptorSetWithTemplate vkUpdateDescriptorSetWithTemplate;
#endif // defined(VK_VERSION_1_1)
#if defined(VK_AMD_buffer_marker)
extern PFN_vkCmdWriteBufferMarkerAMD vkCmdWriteBufferMarkerAMD;
#endif // defined(VK_AMD_buffer_marker)
#if defined(VK_AMD_draw_indirect_count)
extern PFN_vkCmdDrawIndexedIndirectCountAMD vkCmdDrawIndexedIndirectCountAMD;
extern PFN_vkCmdDrawIndirectCountAMD vkCmdDrawIndirectCountAMD;
#endif // defined(VK_AMD_draw_indirect_count)
#if defined(VK_AMD_shader_info)
extern PFN_vkGetShaderInfoAMD vkGetShaderInfoAMD;
#endif // defined(VK_AMD_shader_info)
#if defined(VK_ANDROID_external_memory_android_hardware_buffer)
extern PFN_vkGetAndroidHardwareBufferPropertiesANDROID vkGetAndroidHardwareBufferPropertiesANDROID;
extern PFN_vkGetMemoryAndroidHardwareBufferANDROID vkGetMemoryAndroidHardwareBufferANDROID;
#endif // defined(VK_ANDROID_external_memory_android_hardware_buffer)
#if defined(VK_ANDROID_native_buffer)
extern PFN_vkAcquireImageANDROID vkAcquireImageANDROID;
extern PFN_vkGetSwapchainGrallocUsageANDROID vkGetSwapchainGrallocUsageANDROID;
extern PFN_vkQueueSignalReleaseImageANDROID vkQueueSignalReleaseImageANDROID;
#endif // defined(VK_ANDROID_native_buffer)
#if defined(VK_EXT_acquire_xlib_display)
extern PFN_vkAcquireXlibDisplayEXT vkAcquireXlibDisplayEXT;
extern PFN_vkGetRandROutputDisplayEXT vkGetRandROutputDisplayEXT;
#endif // defined(VK_EXT_acquire_xlib_display)
#if defined(VK_EXT_debug_marker)
extern PFN_vkCmdDebugMarkerBeginEXT vkCmdDebugMarkerBeginEXT;
extern PFN_vkCmdDebugMarkerEndEXT vkCmdDebugMarkerEndEXT;
extern PFN_vkCmdDebugMarkerInsertEXT vkCmdDebugMarkerInsertEXT;
extern PFN_vkDebugMarkerSetObjectNameEXT vkDebugMarkerSetObjectNameEXT;
extern PFN_vkDebugMarkerSetObjectTagEXT vkDebugMarkerSetObjectTagEXT;
#endif // defined(VK_EXT_debug_marker)
#if defined(VK_EXT_debug_report)
extern PFN_vkCreateDebugReportCallbackEXT vkCreateDebugReportCallbackEXT;
extern PFN_vkDebugReportMessageEXT vkDebugReportMessageEXT;
extern PFN_vkDestroyDebugReportCallbackEXT vkDestroyDebugReportCallbackEXT;
#endif // defined(VK_EXT_debug_report)
#if defined(VK_EXT_debug_utils)
extern PFN_vkCmdBeginDebugUtilsLabelEXT vkCmdBeginDebugUtilsLabelEXT;
extern PFN_vkCmdEndDebugUtilsLabelEXT vkCmdEndDebugUtilsLabelEXT;
extern PFN_vkCmdInsertDebugUtilsLabelEXT vkCmdInsertDebugUtilsLabelEXT;
extern PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessengerEXT;
extern PFN_vkDestroyDebugUtilsMessengerEXT vkDestroyDebugUtilsMessengerEXT;
extern PFN_vkQueueBeginDebugUtilsLabelEXT vkQueueBeginDebugUtilsLabelEXT;
extern PFN_vkQueueEndDebugUtilsLabelEXT vkQueueEndDebugUtilsLabelEXT;
extern PFN_vkQueueInsertDebugUtilsLabelEXT vkQueueInsertDebugUtilsLabelEXT;
extern PFN_vkSetDebugUtilsObjectNameEXT vkSetDebugUtilsObjectNameEXT;
extern PFN_vkSetDebugUtilsObjectTagEXT vkSetDebugUtilsObjectTagEXT;
extern PFN_vkSubmitDebugUtilsMessageEXT vkSubmitDebugUtilsMessageEXT;
#endif // defined(VK_EXT_debug_utils)
#if defined(VK_EXT_direct_mode_display)
extern PFN_vkReleaseDisplayEXT vkReleaseDisplayEXT;
#endif // defined(VK_EXT_direct_mode_display)
#if defined(VK_EXT_discard_rectangles)
extern PFN_vkCmdSetDiscardRectangleEXT vkCmdSetDiscardRectangleEXT;
#endif // defined(VK_EXT_discard_rectangles)
#if defined(VK_EXT_display_control)
extern PFN_vkDisplayPowerControlEXT vkDisplayPowerControlEXT;
extern PFN_vkGetSwapchainCounterEXT vkGetSwapchainCounterEXT;
extern PFN_vkRegisterDeviceEventEXT vkRegisterDeviceEventEXT;
extern PFN_vkRegisterDisplayEventEXT vkRegisterDisplayEventEXT;
#endif // defined(VK_EXT_display_control)
#if defined(VK_EXT_display_surface_counter)
extern PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT vkGetPhysicalDeviceSurfaceCapabilities2EXT;
#endif // defined(VK_EXT_display_surface_counter)
#if defined(VK_EXT_external_memory_host)
extern PFN_vkGetMemoryHostPointerPropertiesEXT vkGetMemoryHostPointerPropertiesEXT;
#endif // defined(VK_EXT_external_memory_host)
#if defined(VK_EXT_hdr_metadata)
extern PFN_vkSetHdrMetadataEXT vkSetHdrMetadataEXT;
#endif // defined(VK_EXT_hdr_metadata)
#if defined(VK_EXT_sample_locations)
extern PFN_vkCmdSetSampleLocationsEXT vkCmdSetSampleLocationsEXT;
extern PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT vkGetPhysicalDeviceMultisamplePropertiesEXT;
#endif // defined(VK_EXT_sample_locations)
#if defined(VK_EXT_validation_cache)
extern PFN_vkCreateValidationCacheEXT vkCreateValidationCacheEXT;
extern PFN_vkDestroyValidationCacheEXT vkDestroyValidationCacheEXT;
extern PFN_vkGetValidationCacheDataEXT vkGetValidationCacheDataEXT;
extern PFN_vkMergeValidationCachesEXT vkMergeValidationCachesEXT;
#endif // defined(VK_EXT_validation_cache)
#if defined(VK_GOOGLE_display_timing)
extern PFN_vkGetPastPresentationTimingGOOGLE vkGetPastPresentationTimingGOOGLE;
extern PFN_vkGetRefreshCycleDurationGOOGLE vkGetRefreshCycleDurationGOOGLE;
#endif // defined(VK_GOOGLE_display_timing)
#if defined(VK_KHR_android_surface)
extern PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHR;
#endif // defined(VK_KHR_android_surface)
#if defined(VK_KHR_bind_memory2)
extern PFN_vkBindBufferMemory2KHR vkBindBufferMemory2KHR;
extern PFN_vkBindImageMemory2KHR vkBindImageMemory2KHR;
#endif // defined(VK_KHR_bind_memory2)
#if defined(VK_KHR_descriptor_update_template)
extern PFN_vkCreateDescriptorUpdateTemplateKHR vkCreateDescriptorUpdateTemplateKHR;
extern PFN_vkDestroyDescriptorUpdateTemplateKHR vkDestroyDescriptorUpdateTemplateKHR;
extern PFN_vkUpdateDescriptorSetWithTemplateKHR vkUpdateDescriptorSetWithTemplateKHR;
#endif // defined(VK_KHR_descriptor_update_template)
#if defined(VK_KHR_device_group)
extern PFN_vkCmdDispatchBaseKHR vkCmdDispatchBaseKHR;
extern PFN_vkCmdSetDeviceMaskKHR vkCmdSetDeviceMaskKHR;
extern PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR vkGetDeviceGroupPeerMemoryFeaturesKHR;
#endif // defined(VK_KHR_device_group)
#if defined(VK_KHR_device_group_creation)
extern PFN_vkEnumeratePhysicalDeviceGroupsKHR vkEnumeratePhysicalDeviceGroupsKHR;
#endif // defined(VK_KHR_device_group_creation)
#if defined(VK_KHR_display)
extern PFN_vkCreateDisplayModeKHR vkCreateDisplayModeKHR;
extern PFN_vkCreateDisplayPlaneSurfaceKHR vkCreateDisplayPlaneSurfaceKHR;
extern PFN_vkGetDisplayModePropertiesKHR vkGetDisplayModePropertiesKHR;
extern PFN_vkGetDisplayPlaneCapabilitiesKHR vkGetDisplayPlaneCapabilitiesKHR;
extern PFN_vkGetDisplayPlaneSupportedDisplaysKHR vkGetDisplayPlaneSupportedDisplaysKHR;
extern PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
extern PFN_vkGetPhysicalDeviceDisplayPropertiesKHR vkGetPhysicalDeviceDisplayPropertiesKHR;
#endif // defined(VK_KHR_display)
#if defined(VK_KHR_display_swapchain)
extern PFN_vkCreateSharedSwapchainsKHR vkCreateSharedSwapchainsKHR;
#endif // defined(VK_KHR_display_swapchain)
#if defined(VK_KHR_external_fence_capabilities)
extern PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR vkGetPhysicalDeviceExternalFencePropertiesKHR;
#endif // defined(VK_KHR_external_fence_capabilities)
#if defined(VK_KHR_external_fence_fd)
extern PFN_vkGetFenceFdKHR vkGetFenceFdKHR;
extern PFN_vkImportFenceFdKHR vkImportFenceFdKHR;
#endif // defined(VK_KHR_external_fence_fd)
#if defined(VK_KHR_external_fence_win32)
extern PFN_vkGetFenceWin32HandleKHR vkGetFenceWin32HandleKHR;
extern PFN_vkImportFenceWin32HandleKHR vkImportFenceWin32HandleKHR;
#endif // defined(VK_KHR_external_fence_win32)
#if defined(VK_KHR_external_memory_capabilities)
extern PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR vkGetPhysicalDeviceExternalBufferPropertiesKHR;
#endif // defined(VK_KHR_external_memory_capabilities)
#if defined(VK_KHR_external_memory_fd)
extern PFN_vkGetMemoryFdKHR vkGetMemoryFdKHR;
extern PFN_vkGetMemoryFdPropertiesKHR vkGetMemoryFdPropertiesKHR;
#endif // defined(VK_KHR_external_memory_fd)
#if defined(VK_KHR_external_memory_win32)
extern PFN_vkGetMemoryWin32HandleKHR vkGetMemoryWin32HandleKHR;
extern PFN_vkGetMemoryWin32HandlePropertiesKHR vkGetMemoryWin32HandlePropertiesKHR;
#endif // defined(VK_KHR_external_memory_win32)
#if defined(VK_KHR_external_semaphore_capabilities)
extern PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;
#endif // defined(VK_KHR_external_semaphore_capabilities)
#if defined(VK_KHR_external_semaphore_fd)
extern PFN_vkGetSemaphoreFdKHR vkGetSemaphoreFdKHR;
extern PFN_vkImportSemaphoreFdKHR vkImportSemaphoreFdKHR;
#endif // defined(VK_KHR_external_semaphore_fd)
#if defined(VK_KHR_external_semaphore_win32)
extern PFN_vkGetSemaphoreWin32HandleKHR vkGetSemaphoreWin32HandleKHR;
extern PFN_vkImportSemaphoreWin32HandleKHR vkImportSemaphoreWin32HandleKHR;
#endif // defined(VK_KHR_external_semaphore_win32)
#if defined(VK_KHR_get_memory_requirements2)
extern PFN_vkGetBufferMemoryRequirements2KHR vkGetBufferMemoryRequirements2KHR;
extern PFN_vkGetImageMemoryRequirements2KHR vkGetImageMemoryRequirements2KHR;
extern PFN_vkGetImageSparseMemoryRequirements2KHR vkGetImageSparseMemoryRequirements2KHR;
#endif // defined(VK_KHR_get_memory_requirements2)
#if defined(VK_KHR_get_physical_device_properties2)
extern PFN_vkGetPhysicalDeviceFeatures2KHR vkGetPhysicalDeviceFeatures2KHR;
extern PFN_vkGetPhysicalDeviceFormatProperties2KHR vkGetPhysicalDeviceFormatProperties2KHR;
extern PFN_vkGetPhysicalDeviceImageFormatProperties2KHR vkGetPhysicalDeviceImageFormatProperties2KHR;
extern PFN_vkGetPhysicalDeviceMemoryProperties2KHR vkGetPhysicalDeviceMemoryProperties2KHR;
extern PFN_vkGetPhysicalDeviceProperties2KHR vkGetPhysicalDeviceProperties2KHR;
extern PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR vkGetPhysicalDeviceQueueFamilyProperties2KHR;
extern PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
#endif // defined(VK_KHR_get_physical_device_properties2)
#if defined(VK_KHR_get_surface_capabilities2)
extern PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR vkGetPhysicalDeviceSurfaceCapabilities2KHR;
extern PFN_vkGetPhysicalDeviceSurfaceFormats2KHR vkGetPhysicalDeviceSurfaceFormats2KHR;
#endif // defined(VK_KHR_get_surface_capabilities2)
#if defined(VK_KHR_maintenance1)
extern PFN_vkTrimCommandPoolKHR vkTrimCommandPoolKHR;
#endif // defined(VK_KHR_maintenance1)
#if defined(VK_KHR_maintenance3)
extern PFN_vkGetDescriptorSetLayoutSupportKHR vkGetDescriptorSetLayoutSupportKHR;
#endif // defined(VK_KHR_maintenance3)
#if defined(VK_KHR_mir_surface)
extern PFN_vkCreateMirSurfaceKHR vkCreateMirSurfaceKHR;
extern PFN_vkGetPhysicalDeviceMirPresentationSupportKHR vkGetPhysicalDeviceMirPresentationSupportKHR;
#endif // defined(VK_KHR_mir_surface)
#if defined(VK_KHR_push_descriptor)
extern PFN_vkCmdPushDescriptorSetKHR vkCmdPushDescriptorSetKHR;
#endif // defined(VK_KHR_push_descriptor)
#if defined(VK_KHR_sampler_ycbcr_conversion)
extern PFN_vkCreateSamplerYcbcrConversionKHR vkCreateSamplerYcbcrConversionKHR;
extern PFN_vkDestroySamplerYcbcrConversionKHR vkDestroySamplerYcbcrConversionKHR;
#endif // defined(VK_KHR_sampler_ycbcr_conversion)
#if defined(VK_KHR_shared_presentable_image)
extern PFN_vkGetSwapchainStatusKHR vkGetSwapchainStatusKHR;
#endif // defined(VK_KHR_shared_presentable_image)
#if defined(VK_KHR_surface)
extern PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR;
extern PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
extern PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR;
extern PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR;
extern PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR;
#endif // defined(VK_KHR_surface)
#if defined(VK_KHR_swapchain)
extern PFN_vkAcquireNextImageKHR vkAcquireNextImageKHR;
extern PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR;
extern PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR;
extern PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR;
extern PFN_vkQueuePresentKHR vkQueuePresentKHR;
#endif // defined(VK_KHR_swapchain)
#if defined(VK_KHR_wayland_surface)
extern PFN_vkCreateWaylandSurfaceKHR vkCreateWaylandSurfaceKHR;
extern PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR vkGetPhysicalDeviceWaylandPresentationSupportKHR;
#endif // defined(VK_KHR_wayland_surface)
#if defined(VK_KHR_win32_surface)
extern PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR;
extern PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vkGetPhysicalDeviceWin32PresentationSupportKHR;
#endif // defined(VK_KHR_win32_surface)
#if defined(VK_KHR_xcb_surface)
extern PFN_vkCreateXcbSurfaceKHR vkCreateXcbSurfaceKHR;
extern PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR vkGetPhysicalDeviceXcbPresentationSupportKHR;
#endif // defined(VK_KHR_xcb_surface)
#if defined(VK_KHR_xlib_surface)
extern PFN_vkCreateXlibSurfaceKHR vkCreateXlibSurfaceKHR;
extern PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR vkGetPhysicalDeviceXlibPresentationSupportKHR;
#endif // defined(VK_KHR_xlib_surface)
#if defined(VK_MVK_ios_surface)
extern PFN_vkCreateIOSSurfaceMVK vkCreateIOSSurfaceMVK;
#endif // defined(VK_MVK_ios_surface)
#if defined(VK_MVK_macos_surface)
extern PFN_vkCreateMacOSSurfaceMVK vkCreateMacOSSurfaceMVK;
#endif // defined(VK_MVK_macos_surface)
#if defined(VK_NN_vi_surface)
extern PFN_vkCreateViSurfaceNN vkCreateViSurfaceNN;
#endif // defined(VK_NN_vi_surface)
#if defined(VK_NVX_device_generated_commands)
extern PFN_vkCmdProcessCommandsNVX vkCmdProcessCommandsNVX;
extern PFN_vkCmdReserveSpaceForCommandsNVX vkCmdReserveSpaceForCommandsNVX;
extern PFN_vkCreateIndirectCommandsLayoutNVX vkCreateIndirectCommandsLayoutNVX;
extern PFN_vkCreateObjectTableNVX vkCreateObjectTableNVX;
extern PFN_vkDestroyIndirectCommandsLayoutNVX vkDestroyIndirectCommandsLayoutNVX;
extern PFN_vkDestroyObjectTableNVX vkDestroyObjectTableNVX;
extern PFN_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX;
extern PFN_vkRegisterObjectsNVX vkRegisterObjectsNVX;
extern PFN_vkUnregisterObjectsNVX vkUnregisterObjectsNVX;
#endif // defined(VK_NVX_device_generated_commands)
#if defined(VK_NV_clip_space_w_scaling)
extern PFN_vkCmdSetViewportWScalingNV vkCmdSetViewportWScalingNV;
#endif // defined(VK_NV_clip_space_w_scaling)
#if defined(VK_NV_external_memory_capabilities)
extern PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV vkGetPhysicalDeviceExternalImageFormatPropertiesNV;
#endif // defined(VK_NV_external_memory_capabilities)
#if defined(VK_NV_external_memory_win32)
extern PFN_vkGetMemoryWin32HandleNV vkGetMemoryWin32HandleNV;
#endif // defined(VK_NV_external_memory_win32)
#if (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1))
extern PFN_vkCmdPushDescriptorSetWithTemplateKHR vkCmdPushDescriptorSetWithTemplateKHR;
#endif // (defined(VK_KHR_descriptor_update_template) && defined(VK_KHR_push_descriptor)) || (defined(VK_KHR_push_descriptor) && defined(VK_VERSION_1_1))
#if (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
extern PFN_vkGetDeviceGroupPresentCapabilitiesKHR vkGetDeviceGroupPresentCapabilitiesKHR;
extern PFN_vkGetDeviceGroupSurfacePresentModesKHR vkGetDeviceGroupSurfacePresentModesKHR;
extern PFN_vkGetPhysicalDevicePresentRectanglesKHR vkGetPhysicalDevicePresentRectanglesKHR;
#endif // (defined(VK_KHR_device_group) && defined(VK_KHR_surface)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
#if (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))
extern PFN_vkAcquireNextImage2KHR vkAcquireNextImage2KHR;
#endif // (defined(VK_KHR_device_group) && defined(VK_KHR_swapchain)) || (defined(VK_KHR_swapchain) && defined(VK_VERSION_1_1))

#if !defined(NDEBUG)
#include <iostream>
std::ostream& operator<<(std::ostream& out, const VkImageLayout& value);
std::ostream& operator<<(std::ostream& out, const VkAttachmentLoadOp& value);
std::ostream& operator<<(std::ostream& out, const VkAttachmentStoreOp& value);
std::ostream& operator<<(std::ostream& out, const VkImageType& value);
std::ostream& operator<<(std::ostream& out, const VkImageTiling& value);
std::ostream& operator<<(std::ostream& out, const VkImageViewType& value);
std::ostream& operator<<(std::ostream& out, const VkCommandBufferLevel& value);
std::ostream& operator<<(std::ostream& out, const VkComponentSwizzle& value);
std::ostream& operator<<(std::ostream& out, const VkDescriptorType& value);
std::ostream& operator<<(std::ostream& out, const VkQueryType& value);
std::ostream& operator<<(std::ostream& out, const VkBorderColor& value);
std::ostream& operator<<(std::ostream& out, const VkPipelineBindPoint& value);
std::ostream& operator<<(std::ostream& out, const VkPipelineCacheHeaderVersion& value);
std::ostream& operator<<(std::ostream& out, const VkPrimitiveTopology& value);
std::ostream& operator<<(std::ostream& out, const VkSharingMode& value);
std::ostream& operator<<(std::ostream& out, const VkIndexType& value);
std::ostream& operator<<(std::ostream& out, const VkFilter& value);
std::ostream& operator<<(std::ostream& out, const VkSamplerMipmapMode& value);
std::ostream& operator<<(std::ostream& out, const VkSamplerAddressMode& value);
std::ostream& operator<<(std::ostream& out, const VkCompareOp& value);
std::ostream& operator<<(std::ostream& out, const VkPolygonMode& value);
std::ostream& operator<<(std::ostream& out, const VkFrontFace& value);
std::ostream& operator<<(std::ostream& out, const VkBlendFactor& value);
std::ostream& operator<<(std::ostream& out, const VkBlendOp& value);
std::ostream& operator<<(std::ostream& out, const VkStencilOp& value);
std::ostream& operator<<(std::ostream& out, const VkLogicOp& value);
std::ostream& operator<<(std::ostream& out, const VkInternalAllocationType& value);
std::ostream& operator<<(std::ostream& out, const VkSystemAllocationScope& value);
std::ostream& operator<<(std::ostream& out, const VkPhysicalDeviceType& value);
std::ostream& operator<<(std::ostream& out, const VkVertexInputRate& value);
std::ostream& operator<<(std::ostream& out, const VkFormat& value);
std::ostream& operator<<(std::ostream& out, const VkStructureType& value);
std::ostream& operator<<(std::ostream& out, const VkSubpassContents& value);
std::ostream& operator<<(std::ostream& out, const VkResult& value);
std::ostream& operator<<(std::ostream& out, const VkDynamicState& value);
std::ostream& operator<<(std::ostream& out, const VkDescriptorUpdateTemplateType& value);
std::ostream& operator<<(std::ostream& out, const VkObjectType& value);
std::ostream& operator<<(std::ostream& out, const VkPresentModeKHR& value);
std::ostream& operator<<(std::ostream& out, const VkColorSpaceKHR& value);
std::ostream& operator<<(std::ostream& out, const VkDebugReportObjectTypeEXT& value);
std::ostream& operator<<(std::ostream& out, const VkRasterizationOrderAMD& value);
std::ostream& operator<<(std::ostream& out, const VkValidationCheckEXT& value);
std::ostream& operator<<(std::ostream& out, const VkIndirectCommandsTokenTypeNVX& value);
std::ostream& operator<<(std::ostream& out, const VkObjectEntryTypeNVX& value);
std::ostream& operator<<(std::ostream& out, const VkDisplayPowerStateEXT& value);
std::ostream& operator<<(std::ostream& out, const VkDeviceEventTypeEXT& value);
std::ostream& operator<<(std::ostream& out, const VkDisplayEventTypeEXT& value);
std::ostream& operator<<(std::ostream& out, const VkViewportCoordinateSwizzleNV& value);
std::ostream& operator<<(std::ostream& out, const VkDiscardRectangleModeEXT& value);
std::ostream& operator<<(std::ostream& out, const VkPointClippingBehavior& value);
std::ostream& operator<<(std::ostream& out, const VkSamplerReductionModeEXT& value);
std::ostream& operator<<(std::ostream& out, const VkTessellationDomainOrigin& value);
std::ostream& operator<<(std::ostream& out, const VkSamplerYcbcrModelConversion& value);
std::ostream& operator<<(std::ostream& out, const VkSamplerYcbcrRange& value);
std::ostream& operator<<(std::ostream& out, const VkChromaLocation& value);
std::ostream& operator<<(std::ostream& out, const VkBlendOverlapEXT& value);
std::ostream& operator<<(std::ostream& out, const VkCoverageModulationModeNV& value);
std::ostream& operator<<(std::ostream& out, const VkValidationCacheHeaderVersionEXT& value);
std::ostream& operator<<(std::ostream& out, const VkShaderInfoTypeAMD& value);
std::ostream& operator<<(std::ostream& out, const VkQueueGlobalPriorityEXT& value);
std::ostream& operator<<(std::ostream& out, const VkConservativeRasterizationModeEXT& value);
std::ostream& operator<<(std::ostream& out, const VkCullModeFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkQueueFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkDeviceQueueCreateFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkMemoryPropertyFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkMemoryHeapFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkAccessFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkBufferUsageFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkBufferCreateFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkShaderStageFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkImageUsageFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkImageCreateFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkPipelineCreateFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkColorComponentFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkFenceCreateFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkFormatFeatureFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkQueryControlFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkQueryResultFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkCommandBufferUsageFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkQueryPipelineStatisticFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkImageAspectFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkSparseImageFormatFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkSparseMemoryBindFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkPipelineStageFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkCommandPoolCreateFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkCommandPoolResetFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkCommandBufferResetFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkSampleCountFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkAttachmentDescriptionFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkStencilFaceFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkDescriptorPoolCreateFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkDependencyFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkDisplayPlaneAlphaFlagBitsKHR& value);
std::ostream& operator<<(std::ostream& out, const VkCompositeAlphaFlagBitsKHR& value);
std::ostream& operator<<(std::ostream& out, const VkSurfaceTransformFlagBitsKHR& value);
std::ostream& operator<<(std::ostream& out, const VkDebugReportFlagBitsEXT& value);
std::ostream& operator<<(std::ostream& out, const VkExternalMemoryHandleTypeFlagBitsNV& value);
std::ostream& operator<<(std::ostream& out, const VkExternalMemoryFeatureFlagBitsNV& value);
std::ostream& operator<<(std::ostream& out, const VkSubgroupFeatureFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkIndirectCommandsLayoutUsageFlagBitsNVX& value);
std::ostream& operator<<(std::ostream& out, const VkObjectEntryUsageFlagBitsNVX& value);
std::ostream& operator<<(std::ostream& out, const VkDescriptorSetLayoutCreateFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkExternalMemoryHandleTypeFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkExternalMemoryFeatureFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkExternalSemaphoreHandleTypeFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkExternalSemaphoreFeatureFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkSemaphoreImportFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkExternalFenceHandleTypeFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkExternalFenceFeatureFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkFenceImportFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkSurfaceCounterFlagBitsEXT& value);
std::ostream& operator<<(std::ostream& out, const VkPeerMemoryFeatureFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkMemoryAllocateFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkDeviceGroupPresentModeFlagBitsKHR& value);
std::ostream& operator<<(std::ostream& out, const VkSwapchainCreateFlagBitsKHR& value);
std::ostream& operator<<(std::ostream& out, const VkSubpassDescriptionFlagBits& value);
std::ostream& operator<<(std::ostream& out, const VkDebugUtilsMessageSeverityFlagBitsEXT& value);
std::ostream& operator<<(std::ostream& out, const VkDebugUtilsMessageTypeFlagBitsEXT& value);
#endif
