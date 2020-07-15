#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>

using namespace std;
using namespace glm;

class Shader {
private:
	unsigned int b_ShaderProgramHandle;
public:
	Shader(const GLchar* vertexShaderPath, const GLchar* fragmentShaderPath);
	void UseShader();
	unsigned int GetShaderProgramHandle();
	//Utility
	void SetBool(const string& name, bool value);
	void SetInt(const string& name, int value);
	void SetFloat(const string& name, float value);
	void SetVec3(const string& name, vec3& value);
	void SetMat4(const string& name, const mat4& value);
	~Shader();
};


