#include "Transform.h"

Transform::Transform()
{
	Position = vec3();
	Rotation = vec3();
	Scale = vec3(1.0f,1.0f,1.0f);
}

Transform::Transform(vec3 pos)
{
	Position = pos;
	Rotation = vec3();
	Scale = vec3();
}

Transform::Transform(vec3 pos, vec3 rot)
{
	Position = pos;
	Rotation = rot;
	Scale = vec3();
}

mat4 Transform::GetTransformMatrix()
{
	return mat4();
}

void Transform::Translate(vec3 delta)
{
	Position += delta;
}

void Transform::Rotate(vec3 axis, float rad)
{
}

Quaterion::Quaterion()
{
	value = vec4();
}

Quaterion::Quaterion(vec4 val)
{
	value = val;
}

Quaterion::Quaterion(vec3 Euler)
{
	
}

vec3 Quaterion::ToEuler()
{
	return vec3();
}
