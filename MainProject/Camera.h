#pragma once
#include <GLAD/glad.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
using namespace glm;
class Camera
{
public:
	vec3 Position;
	vec3 Rotation;

	Camera(vec3 pos, vec3 rot);

	mat4 GetViewMatrix();

	vec3 GetTowardsVector();
private:
	
};

