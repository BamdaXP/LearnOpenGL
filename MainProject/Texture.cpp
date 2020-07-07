#include "Texture.h"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
using namespace std;
Texture::Texture(string path)
{
	//Gen texture buffer in GPU and bind it
	glGenTextures(1, &b_TextureHandle);
	glBindTexture(GL_TEXTURE_2D,b_TextureHandle);
	//Texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Load the texture data
	unsigned char* data =
		stbi_load(
			path.c_str(),
			&b_Width,
			&b_Height,
			&b_Channels,
			0);
	//Load data to GPU
	if (data) {
		glTexImage2D(GL_TEXTURE_2D,
			0,
			GL_RGB,
			b_Width,
			b_Height,
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	

	//Free loaded data
	stbi_image_free(data);
}

void Texture::UseTexture(GLenum textureOrder = GL_TEXTURE0)
{
	glActiveTexture(textureOrder);
	glBindTexture(GL_TEXTURE_2D, b_TextureHandle);
}

int Texture::GetTextureHandle()
{
	return b_TextureHandle;
}

int Texture::GetWidth()
{
	return b_Width;
}

int Texture::GetHeight()
{
	return b_Height;
}
