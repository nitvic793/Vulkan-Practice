#pragma once

#include <vulkan/vulkan.h>

struct Texture
{
	VkFormat TextureFormat;
	int Width;
	int Height;
	int MipLevels;
	VkDeviceSize ImageSize;
	VkImage Image;
	VkDeviceMemory ImageMemory;
	VkImageView ImageView;
};

