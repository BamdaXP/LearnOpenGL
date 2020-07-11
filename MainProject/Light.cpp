#include "Light.h"
#include "Shader.h"
Light::Light()
{
	Color = vec3(1,1,1);
	Intensity = 5.0f;
}

void Light::UseLight(Shader& shader)
{
	shader.SetVec3("lightPos",Transform.Position);
	shader.SetVec3("lightColor", Color);
	shader.SetFloat("intensity", Intensity);
}
