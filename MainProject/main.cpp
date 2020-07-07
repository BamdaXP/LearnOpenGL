//GLAD includes the dynamic retrieved OpengGL function definitions
//So must include it first or the gflw will miss some header includes
#include<iostream>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

//Declarations
void Render();
void ResizeCallback(GLFWwindow* window, int width, int height);
void ProcessInput(GLFWwindow* window);

int main() {
	//GLFW initialization
	glfwInit();
	//Use the GLFW 3.3 Version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	//Access to small subsets of OpengGL features
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Mac OS options
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	
	//Create the window and get the handle
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "MyGame", NULL, NULL);
	//Handle the exception
	if (window == NULL) {
		std::cout << "Failed to create the GLFW window!"<<std::endl;
		glfwTerminate();
		return -1;//Shut the process
	}

	//Make the current context
	glfwMakeContextCurrent(window);

	//Initiliaze GLAD 
	if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) == NULL) {
		std::cout << "Failed to initialize GLAD!"<<std::endl;
		glfwTerminate();
		return -1;//Shut the process
	}

	//Set the viewport
	//Map coordinates from (-1,1) to (0,width) and (0,height)
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	//Register resize callback
	glfwSetFramebufferSizeCallback(window, ResizeCallback);

	glClearColor(0.3f, 0.3f, 0.8f, 1.0f);
	//Main process
	while (!glfwWindowShouldClose(window)) {
		//Clear the buffer
		glClear(GL_COLOR_BUFFER_BIT);
		//Update key input
		ProcessInput(window);

		/*Do rendering here*/
		Render();
		/*End rendering*/

		//Swap frame buffer
		glfwSwapBuffers(window);
		//Triger pending events
		glfwPollEvents();

		//Clear gl states
		glFlush();
	}

	//Shut down glfw
	glfwTerminate();
	return 0;
}

void Render() {
	Shader shader = Shader("./Shaders/default_vertex_shader.glsl",
		"./Shaders/default_fragment_shader.glsl");
	Texture texture = Texture("./Textures/chibi.png");

	Mesh mesh = Mesh();
	
	mesh.vertices.push_back(Vertex(
		vec3(0.5f, 0.5f, 0.0f),
		vec3(),
		vec3(),
		vec2(0.0f, 0.0f)));
	mesh.vertices.push_back(Vertex(
		vec3(0.5f, -0.5f, 0.0f), 
		vec3(), 
		vec3(),
		vec2(1.0f, 0.0f)));;
	mesh.vertices.push_back(Vertex(
		vec3(-0.5f, -0.5f, 0.0f), 
		vec3(), 
		vec3(),
		vec2(0.5f, 1.0f)));;
	
	mesh.indices.push_back(0);
	mesh.indices.push_back(1);
	mesh.indices.push_back(2);

	mesh.textures.push_back(texture);

	mesh.Draw(shader);
}

void ResizeCallback(GLFWwindow* window,int width,int height) {
	glViewport(0, 0, width, height);
}

void ProcessInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window,true);
}