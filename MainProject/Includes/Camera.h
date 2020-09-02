#pragma once
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include "Transform.h"
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

	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;
	glm::vec3 GetTowardsVector() const;
private:
	
};

