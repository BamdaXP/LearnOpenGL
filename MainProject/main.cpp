//GLAD includes the dynamic retrieved OpengGL function definitions
//So must include it first or the gflw will miss some header includes
#include<iostream>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Camera.h"
#include "Time.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

//Declarations
void ResizeCallback(GLFWwindow* window, int width, int height);
void MouseCallback(GLFWwindow* window, double xpos, double ypos);
void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
void ProcessInput(GLFWwindow* window);

//Init Objects
Camera camera = Camera();


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
	Camera::ScreenWidth = WINDOW_WIDTH;
	Camera::ScreenHeight = WINDOW_HEIGHT;
	//Register callbacks
	glfwSetFramebufferSizeCallback(window, ResizeCallback);
	glfwSetCursorPosCallback(window, MouseCallback);
	glfwSetScrollCallback(window, ScrollCallback);

	Shader shader = Shader("./Shaders/default_vertex_shader.glsl",
		"./Shaders/default_fragment_shader.glsl");
	Texture texture = Texture("./Textures/chibi.png");
	Mesh mesh = Mesh();

	mesh.Vertices.push_back(Vertex(
		vec3(0.0f, 0.0f, 0.0f),
		vec3(1.0f),
		vec3(),
		vec2(0.0f, 0.0f)));
	mesh.Vertices.push_back(Vertex(
		vec3(0.5f, 0.0f, 0.0f),
		vec3(1.0f),
		vec3(),
		vec2(1.0f, 0.0f)));;
	mesh.Vertices.push_back(Vertex(
		vec3(0.0f, 1.0f, 0.0f),
		vec3(1.0f),
		vec3(),
		vec2(0.0f, 1.0f)));
	mesh.Vertices.push_back(Vertex(
		vec3(0.0f, 0.0f, 0.5f),
		vec3(1.0f),
		vec3(),
		vec2(1.0f, 1.0f)));
	mesh.Indices.push_back(0);
	mesh.Indices.push_back(1);
	mesh.Indices.push_back(2);

	mesh.Indices.push_back(0);
	mesh.Indices.push_back(3);
	mesh.Indices.push_back(2);

	mesh.Indices.push_back(0);
	mesh.Indices.push_back(1);
	mesh.Indices.push_back(3);

	mesh.Indices.push_back(1);
	mesh.Indices.push_back(3);
	mesh.Indices.push_back(2);

	mesh.Textures.push_back(texture);
	//Main process
	while (!glfwWindowShouldClose(window)) {
		//Clear the buffer
		glClearColor(0.3f, 0.3f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		//Update key input
		ProcessInput(window);

		/*Do rendering here*/
		mesh.Draw(shader);
		mesh.Transform.Rotation.y += 0.5f;

		/*End rendering*/

		//Swap frame buffer
		glfwSwapBuffers(window);
		//Triger pending events
		glfwPollEvents();

		cout << Time::FramesPerSecond() << endl;
		Time::Update();
	}

	//Shut down glfw
	glfwTerminate();
	return 0;
}


void ResizeCallback(GLFWwindow* window,int width,int height) {
	glViewport(0, 0, width, height);
	Camera::ScreenWidth = width;
	Camera::ScreenHeight = height;
}
bool firstMouse = false;
float lastX;
float lastY;
void MouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.1f; // change this value to your liking
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	camera.Transform.Rotation.y += xoffset;
	camera.Transform.Rotation.x += yoffset;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (camera.Transform.Rotation.x > 89.0f)
		camera.Transform.Rotation.x = 89.0f;
	if (camera.Transform.Rotation.x < -89.0f)
		camera.Transform.Rotation.x = -89.0f;

}

void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.fovy -= (float)yoffset;
	if (camera.fovy < 1.0f)
		camera.fovy = 1.0f;
	if (camera.fovy > 45.0f)
		camera.fovy = 45.0f;
}

void ProcessInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window,true);

	float cameraSpeed = 2.5 * Time::DeltaTime();
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		 camera.Transform.Position += cameraSpeed * camera.GetTowardsVector();
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.Transform.Position -= cameraSpeed * camera.GetTowardsVector();
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.Transform.Position -= glm::normalize(glm::cross(camera.GetTowardsVector(), vec3(0.0f,1.0f,0.0f))) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.Transform.Position += glm::normalize(glm::cross(camera.GetTowardsVector(), vec3(0.0f, 1.0f, 0.0f))) * cameraSpeed;
}