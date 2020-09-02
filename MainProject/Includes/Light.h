#pragma once
#include "Transform.h"
class Light
{
public:

	Transform Transform;
	glm::vec3 Color;
	float Intensity;

	Light();
	void UseLight(const class Shader& shader) const;
};

