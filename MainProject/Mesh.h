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
	enum MeshTopology {
		Triangles = 0,
		Quads
	};
	//Object properies
	Transform Transform;

	//Mesh properties
	vector<Vertex> Vertices;
	vector<unsigned int> Indices;
	vector<Texture> Textures;
	
	MeshTopology Topology = Mesh::Triangles;

	Mesh();
	void Draw(class Shader& shader, GLenum drawType = GL_STATIC_DRAW);
	~Mesh();
private:
	bool b_IsSetup;
	unsigned int b_VAO, b_VBO, b_EBO;
	void Setup();
};

