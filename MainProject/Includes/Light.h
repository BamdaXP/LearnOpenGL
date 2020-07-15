#pragma once
#include "Transform.h"
class Light
{
public:

	Transform Transform;
	vec3 Color;
	float Intensity;

	Light();
	void UseLight(class Shader& shader);
};

