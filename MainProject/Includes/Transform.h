#pragma once
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
struct Transform
{
public:
	glm::vec3 Position;
	glm::vec3 Rotation;
	glm::vec3 Scale;

	Transform();
	Transform(const glm::vec3& pos);
	Transform(const glm::vec3& pos, const glm::vec3& rot);
	glm::mat4 GetTransformMatrix() const;
	void Translate(const glm::vec3& delta);
	void Rotate(const glm::vec3& axis,float rad);
};

