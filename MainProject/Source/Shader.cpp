#include "Shader.h"
#include <GLM/gtc/type_ptr.hpp>

/*
const char* Shader::VertexShaderCode =
"#version 420 core\n layout (location=0) in vec3 aPos;\n void main(){\n gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);}";
const char* Shader::FragmentShaderCode =
"version 420 core\n out vec4 FragColor;\n void main(){\n FragColor = vec4(1.0f,0.5f,0.5f,1.0f);}";
Shader::Shader(char* code, GLenum type) {
	b_Code = code;
	b_Type = type;
	b_ShaderHandle = glCreateShader(b_Type);
	glShaderSource(b_ShaderHandle, 1, &code, NULL);
	glCompileShader(b_ShaderHandle);

	glGetShaderiv(b_ShaderHandle, GL_COMPILE_STATUS, &b_Success);
	glGetShaderInfoLog(b_ShaderHandle, 512, NULL, b_Log);

	if (!b_Success) {
		std::cout << "Shader compile failed!\n" << b_Log << std::endl;
	}
}

unsigned int Shader::GetShaderHandle()
{
	return b_ShaderHandle;
}

int Shader::IsSuccess() {
	return b_Success;
}

char* Shader::GetLog() {
	return b_Log;
}

Shader::~Shader()
{
	glDeleteShader(b_ShaderHandle);
}
*/
using namespace std;
Shader::Shader(const GLchar* vertexShaderPath, const GLchar* fragmentShaderPath)
{
	string vShaderCode;
	string fShaderCode;
	ifstream vShaderFile;
	ifstream fShaderFile;

	vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);

	try {
		//Open files
		vShaderFile.open(vertexShaderPath);
		fShaderFile.open(fragmentShaderPath);
		//Read file contents into streams
		stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		//Close files
		vShaderFile.close();
		fShaderFile.close();
		//Cast stream to string
		vShaderCode = vShaderStream.str();
		fShaderCode = fShaderStream.str();
	}
	catch (ifstream::failure e) {
		cout << "Shader file read failed!" << endl;
	}
	//Shader handles
	unsigned int vShaderHandle, fShaderHandle;

	//Logging
	int success;
	char infoLog[512];

	//Create shaders in GL
	const char* vCode = vShaderCode.c_str();
	const char* fCode = fShaderCode.c_str();
	vShaderHandle = glCreateShader(GL_VERTEX_SHADER);
	fShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vShaderHandle, 1, &vCode, NULL);
	glShaderSource(fShaderHandle, 1, &fCode, NULL);

	//Vertex shader compile
	glCompileShader(vShaderHandle);

	//Logging
	glGetShaderiv(vShaderHandle, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vShaderHandle, 512, NULL, infoLog);
		cout << "Vertex shader compile failed!\n" << infoLog << endl;
	}


	//Fragment shader compile
	glCompileShader(fShaderHandle);
	//Logging
	glGetShaderiv(fShaderHandle, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fShaderHandle, 512, NULL, infoLog);
		cout << "Fragment shader compile failed!\n" << infoLog << endl;
	}

	//Create shader program
	b_ShaderProgramHandle = glCreateProgram();
	glAttachShader(b_ShaderProgramHandle, vShaderHandle);
	glAttachShader(b_ShaderProgramHandle, fShaderHandle);
	glLinkProgram(b_ShaderProgramHandle);

	glGetProgramiv(b_ShaderProgramHandle, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(b_ShaderProgramHandle, 512, NULL, infoLog);
		cout << "Shader program link failed!\n" << infoLog << endl;
	}

	//Delete shader we used
	glDeleteShader(vShaderHandle);
	glDeleteShader(fShaderHandle);
}

void Shader::UseShader()
{
	glUseProgram(b_ShaderProgramHandle);
}

unsigned int Shader::GetShaderProgramHandle()
{
	return b_ShaderProgramHandle;
}


//Shader parameter utilities
void Shader::SetBool(const string& name, bool value)
{
	glUniform1i(glGetUniformLocation(b_ShaderProgramHandle,name.c_str()), (int)value);
}

void Shader::SetInt(const string& name, int value)
{
	glUniform1i(glGetUniformLocation(b_ShaderProgramHandle, name.c_str()), value);
}

void Shader::SetFloat(const string& name, float value)
{
	glUniform1f(glGetUniformLocation(b_ShaderProgramHandle, name.c_str()), value);
}

void Shader::SetVec3(const string& name, vec3& value)
{
	unsigned int vec3Handle = glGetUniformLocation(b_ShaderProgramHandle, name.c_str());
	glUniform3fv(vec3Handle, 1, value_ptr(value));
}

void Shader::SetMat4(const string& name, const mat4& value)
{
	unsigned int mat4Handle = glGetUniformLocation(b_ShaderProgramHandle, name.c_str());
	glUniformMatrix4fv(mat4Handle, 1, GL_FALSE, value_ptr(value));
}

Shader::~Shader() {
	glDeleteProgram(b_ShaderProgramHandle);
}
