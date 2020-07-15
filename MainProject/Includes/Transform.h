#pragma once
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
using namespace glm;
struct Transform
{
public:
	vec3 Position;
	vec3 Rotation;
	vec3 Scale;

	Transform();
	Transform(vec3 pos);
	Transform(vec3 pos, vec3 rot);
	mat4 GetTransformMatrix();
	void Translate(vec3 delta);
	void Rotate(vec3 axis,float rad);
};

