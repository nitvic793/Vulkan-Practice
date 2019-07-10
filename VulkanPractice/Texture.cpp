#include "Texture.h"

TextureID TextureManager::AddTexture(const std::string& filename)
{
	TextureID texID = (TextureID)textureFileNames.size();
	textureFileNames.push_back(filename);
	return texID;
}

const uint32_t TextureManager::TextureCount()
{
	return (uint32_t)textures.size();
}
