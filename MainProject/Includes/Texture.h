#pragma once

#include <string>
class Texture
{
private:
	unsigned int b_TextureHandle;
	int b_Width;
	int b_Height;
	int b_Channels;
public:
	Texture(const std::string& path);
	int GetTextureHandle() const;
	int GetWidth() const;
	int GetHeight() const;
	~Texture();
};

