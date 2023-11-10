#pragma once

#include <GLFW/glfw3.h>

struct GLFWwindowDeleter 
{
	void operator()(GLFWwindow* ptr)
	{
		glfwDestroyWindow(ptr);
	}
};