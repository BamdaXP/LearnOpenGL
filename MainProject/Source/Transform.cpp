#include "Transform.h"

Transform::Transform()
{
	Position = glm::vec3();
	Rotation = glm::vec3();
	Scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

Transform::Transform(const glm::vec3& pos)
{
	Position = pos;
	Rotation = glm::vec3();
	Scale = glm::vec3();
}

Transform::Transform(const glm::vec3& pos, const glm::vec3& rot)
{
	Position = pos;
	Rotation = rot;
	Scale = glm::vec3();
}

glm::mat4 Transform::GetTransformMatrix() const
{
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::scale(trans, Scale);
	trans = glm::rotate(trans, glm::radians(Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	trans = glm::rotate(trans, glm::radians(Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	trans = glm::rotate(trans, glm::radians(Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	trans = glm::translate(trans, Position);

	return trans;
}

void Transform::Translate(const glm::vec3& delta)
{
	Position += delta;
}

void Transform::Rotate(const glm::vec3& axis, float rad)
{
}