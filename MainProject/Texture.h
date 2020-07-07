#pragma once
#include <string>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
using namespace std;

class Texture
{
private:
	unsigned int b_TextureHandle;
	int b_Width;
	int b_Height;
	int b_Channels;
public:
	Texture(typename std::string path);
	void UseTexture(GLenum textureOrder);
	int GetTextureHandle();
	int GetWidth();
	int GetHeight();
};

