#pragma once
#include <GLM/glm.hpp>
using namespace glm;
struct Vertex {
public:
	vec3 Position;
	vec3 Normal;
	vec3 Color;
	vec2 UV;

	Vertex() {
		Position = vec3();
		Normal = vec3();
		Color = vec3(1.0f, 1.0f, 1.0f);
		UV = vec2();
	}
	Vertex(vec3 pos,vec3 normal,vec3 color,vec2 uv) {
		Position = pos;
		Normal = normal;
		Color = color;
		UV = uv;
	}
};