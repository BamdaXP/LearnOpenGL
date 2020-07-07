#include "Camera.h"

Camera::Camera(vec3 pos, vec3 rot)
{
	Position = pos;
	Rotation = rot;
}

mat4 Camera::GetViewMatrix()
{
	return lookAt(Position,Position+GetTowardsVector(),vec3(0.0f,1.0f,0.0f));
}

vec3 Camera::GetTowardsVector()
{
	vec3 toward;
	toward.x = cos(radians(Rotation.y) * cos(radians(Rotation.x)));
	toward.y = sin(radians(Rotation.x));
	toward.z = sin(radians(Rotation.y) * cos(radians(Rotation.x)));
	return toward;
}
