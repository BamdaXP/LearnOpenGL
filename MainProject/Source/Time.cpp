#include "Time.h"
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
double Time::b_CurrentTime = 0.0;
double Time::b_LastTime = 0.0;

double Time::DeltaTime()
{
	return b_CurrentTime - b_LastTime;
}

double Time::FramesPerSecond()
{
	double delta = DeltaTime();
	return delta == 0 ? 0 : 1.0 / delta;
}

void Time::Update()
{
	b_LastTime = b_CurrentTime;
	b_CurrentTime = glfwGetTime();
}