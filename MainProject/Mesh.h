#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "Vertex.h"
#include "Texture.h"
#include <vector>
#include "Transform.h"
using namespace std;
class Mesh
{
public:
	//Object properies
	Transform transform;

	//Mesh properties
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;
	
	Mesh();
	void Draw(class Shader& shader, GLenum drawType = GL_STATIC_DRAW);
private:
	bool b_IsSetup;
	unsigned int VAO, VBO, EBO;
	void Setup();
};

