#include "Camera.h"

Camera* Camera::MainCamera = nullptr;
int Camera::ScreenWidth = 0;
int Camera::ScreenHeight = 0;
Camera::Camera()
{
	Transform.Position.z = 5.0f;
	Transform.Rotation.y = -90.0f;
	//Set main camera
	MainCamera = this;
}

glm::mat4 Camera::GetViewMatrix() const
{
	return glm::lookAt(Transform.Position,
		Transform.Position + GetTowardsVector(),
		glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::GetProjectionMatrix() const
{
	return glm::perspective(glm::radians(fovy), (float)ScreenWidth / ScreenHeight, NearPlane, FarPlane);
}

glm::vec3 Camera::GetTowardsVector() const
{
	glm::vec3 toward;
	toward.x = cos(glm::radians(Transform.Rotation.y) * cos(glm::radians(Transform.Rotation.x)));
	toward.y = sin(glm::radians(Transform.Rotation.x));
	toward.z = sin(glm::radians(Transform.Rotation.y) * cos(glm::radians(Transform.Rotation.x)));
	return toward;
}