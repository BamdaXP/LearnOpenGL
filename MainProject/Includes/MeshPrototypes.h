#pragma once
#include "Mesh.h"
#include "Vertex.h"
class CubeMesh :
	public Mesh
{
public:
	static Vertex QuadVerts[6][4];
	CubeMesh(float size, vec3 color = vec3(1, 1, 1))
	{
		Mesh::Mesh();
		/*
		//z=0
		Vertices.push_back(
			Vertex(
				vec3(0, 0, 0),
				vec3(0, 0, -1),
				color,
				vec2()));
		Vertices.push_back(
			Vertex(
				vec3(size, 0, 0),
				vec3(0, 0, -1),
				color,
				vec2()));
		Vertices.push_back(
			Vertex(vec3(size, size, 0),
				vec3(0, 0, -1),
				color,
				vec2()));
		Vertices.push_back(
			Vertex(vec3(0, size, 0),
				vec3(0, 0, -1),
				color,
				vec2()));

		//z=size
		Vertices.push_back(
			Vertex(
				vec3(0, 0, size),
				vec3(0, 0, 1),
				color,
				vec2()));
		Vertices.push_back(
			Vertex(
				vec3(size, 0, size),
				vec3(0, 0, 1),
				color,
				vec2()));
		Vertices.push_back(
			Vertex(vec3(size, size, size),
				vec3(0, 0, 1),
				color,
				vec2()));
		Vertices.push_back(
			Vertex(vec3(0, size, size),
				vec3(0, 0, 1),
				color,
				vec2()));

		Indices.push_back(0);
		Indices.push_back(2);
		Indices.push_back(1);
		Indices.push_back(0);
		Indices.push_back(3);
		Indices.push_back(2);

		Indices.push_back(4);
		Indices.push_back(5);
		Indices.push_back(6);
		Indices.push_back(4);
		Indices.push_back(6);
		Indices.push_back(7);

		Indices.push_back(0);
		Indices.push_back(4);
		Indices.push_back(7);
		Indices.push_back(0);
		Indices.push_back(7);
		Indices.push_back(3);

		Indices.push_back(5);
		Indices.push_back(1);
		Indices.push_back(2);
		Indices.push_back(5);
		Indices.push_back(2);
		Indices.push_back(6);

		Indices.push_back(7);
		Indices.push_back(6);
		Indices.push_back(2);
		Indices.push_back(7);
		Indices.push_back(6);
		Indices.push_back(3);

		Indices.push_back(0);
		Indices.push_back(1);
		Indices.push_back(5);
		Indices.push_back(0);
		Indices.push_back(5);
		Indices.push_back(4);
		*/

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Vertex v = QuadVerts[i][j];
				v.Color = color;
				v.Position *= size;
				Vertices.push_back(v);
			}
			Indices.push_back(4 * i);
			Indices.push_back(4 * i + 1);
			Indices.push_back(4 * i + 3);
			Indices.push_back(4 * i + 1);
			Indices.push_back(4 * i + 2);
			Indices.push_back(4 * i + 3);
		}
	}
};

Vertex CubeMesh::QuadVerts[6][4] =
{
	{
		Vertex(vec3(0,0,1),vec3(0,-1,0),vec3(1,1,1),vec2(0,0)),
		Vertex(vec3(0,0,0),vec3(0,-1,0),vec3(1,1,1),vec2(1,0)),
		Vertex(vec3(1,0,0),vec3(0,-1,0),vec3(1,1,1),vec2(1,1)),
		Vertex(vec3(1,0,1),vec3(0,-1,0),vec3(1,1,1),vec2(0,1)),
	},
	{
		Vertex(vec3(0,1,0),vec3(0,1,0),vec3(1,1,1),vec2(0,0)),
		Vertex(vec3(0,1,1),vec3(0,1,0),vec3(1,1,1),vec2(1,0)),
		Vertex(vec3(1,1,1),vec3(0,1,0),vec3(1,1,1),vec2(1,1)),
		Vertex(vec3(1,1,0),vec3(0,1,0),vec3(1,1,1),vec2(0,1)),
	},
	{
		Vertex(vec3(1,1,0),vec3(0,0,-1),vec3(1,1,1),vec2(0,0)),
		Vertex(vec3(1,0,0),vec3(0,0,-1),vec3(1,1,1),vec2(1,0)),
		Vertex(vec3(0,0,0),vec3(0,0,-1),vec3(1,1,1),vec2(1,1)),
		Vertex(vec3(0,1,0),vec3(0,0,-1),vec3(1,1,1),vec2(0,1)),
	},
	{
		Vertex(vec3(0,1,1),vec3(0,0,1),vec3(1,1,1),vec2(0,0)),
		Vertex(vec3(0,0,1),vec3(0,0,1),vec3(1,1,1),vec2(1,0)),
		Vertex(vec3(1,0,1),vec3(0,0,1),vec3(1,1,1),vec2(1,1)),
		Vertex(vec3(1,1,1),vec3(0,0,1),vec3(1,1,1),vec2(0,1)),
	},
	{
		Vertex(vec3(0,1,0),vec3(-1,0,0),vec3(1,1,1),vec2(0,0)),
		Vertex(vec3(0,0,0),vec3(-1,0,0),vec3(1,1,1),vec2(1,0)),
		Vertex(vec3(0,0,1),vec3(-1,0,0),vec3(1,1,1),vec2(1,1)),
		Vertex(vec3(0,1,1),vec3(-1,0,0),vec3(1,1,1),vec2(0,1)),
	},
	{
		Vertex(vec3(1,1,1),vec3(1,0,0),vec3(1,1,1),vec2(0,0)),
		Vertex(vec3(1,0,1),vec3(1,0,0),vec3(1,1,1),vec2(1,0)),
		Vertex(vec3(1,0,0),vec3(1,0,0),vec3(1,1,1),vec2(1,1)),
		Vertex(vec3(1,1,0),vec3(1,0,0),vec3(1,1,1),vec2(0,1)),
	},
};
