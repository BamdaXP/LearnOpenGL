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

mat4 Camera::GetViewMatrix()
{
	return lookAt(Transform.Position,
		Transform.Position + GetTowardsVector(),
		vec3(0.0f,1.0f,0.0f));
}

mat4 Camera::GetProjectionMatrix()
{
	return perspective(radians(fovy),(float)ScreenWidth/ScreenHeight , NearPlane, FarPlane);
}

vec3 Camera::GetTowardsVector()
{
	vec3 toward;
	toward.x = cos(radians(Transform.Rotation.y) * cos(radians(Transform.Rotation.x)));
	toward.y = sin(radians(Transform.Rotation.x));
	toward.z = sin(radians(Transform.Rotation.y) * cos(radians(Transform.Rotation.x)));
	return toward;
}
