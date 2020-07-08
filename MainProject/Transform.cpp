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
	mat4 trans = mat4(1.0f);
	trans = scale(trans, Scale);
	trans = rotate(trans, radians(Rotation.x), vec3(1.0f, 0.0f, 0.0f));
	trans = rotate(trans, radians(Rotation.y), vec3(0.0f, 1.0f, 0.0f));
	trans = rotate(trans, radians(Rotation.z), vec3(0.0f, 0.0f, 1.0f));
	trans = translate(trans, Position);
	
	return trans;
}

void Transform::Translate(vec3 delta)
{
	Position += delta;
}

void Transform::Rotate(vec3 axis, float rad)
{
	
}


