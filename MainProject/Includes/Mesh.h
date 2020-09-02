#pragma once
#include <vector>
#include "Transform.h"
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
	std::vector<class Vertex> Vertices;
	std::vector<unsigned int> Indices;
	std::vector<class Texture> Textures;
	
	MeshTopology Topology = Mesh::Triangles;

	Mesh();
	void Draw(const class Shader& shader);
	~Mesh();
private:
	bool b_IsSetup;
	unsigned int b_VAO, b_VBO, b_EBO;
	void Setup();
};

