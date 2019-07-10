#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include <string>

class VulkanApp;

typedef uint32_t TextureID;

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

class TextureManager
{
public:
	friend class VulkanApp;
	TextureID AddTexture(const std::string& filename);
	const uint32_t TextureCount();
protected:
	std::vector<std::string> textureFileNames;
	std::vector<Texture> textures;
};