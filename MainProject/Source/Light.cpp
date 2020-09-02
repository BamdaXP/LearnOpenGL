#include "Light.h"
#include "Shader.h"
Light::Light()
{
	Color = glm::vec3(1, 1, 1);
	Intensity = 5.0f;
}

void Light::UseLight(const Shader& shader) const
{
	shader.SetVec3("lightPos", Transform.Position);
	shader.SetVec3("lightColor", Color);
	shader.SetFloat("intensity", Intensity);
}