#pragma once
#include "Transform.h"
#include <GLAD/glad.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
using namespace glm;
class Camera
{
public:
	enum Projection {
		Perspective = 0,
		Orthogonal
	};
	static Camera* MainCamera;
	static int ScreenWidth;
	static int ScreenHeight;

	Transform Transform;
	Projection Projection = Camera::Perspective;

	float NearPlane = 1.0f;
	float FarPlane = 100.0f;
	float fovy = 45.0f;
	Camera();

	mat4 GetViewMatrix();
	mat4 GetProjectionMatrix();
	vec3 GetTowardsVector();
private:
	
};

