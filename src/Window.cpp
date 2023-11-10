#include "Window.h"
#include <iostream>

Window::Window(std::unique_ptr<WindowParameters> parameters)
{
	if (_initialized) 
	{
		GLFWwindow* window = glfwCreateWindow(
			parameters->width
			, parameters->height
			, parameters->windowName.c_str()
			, nullptr
			, nullptr
		);
		_window = std::unique_ptr<GLFWwindow, GLFWwindowDeleter>(window);
	}

	if (_window)
		std::cout << "Successfully Initialized GLFW Window \n";
}

Window::~Window()
{
	glfwTerminate();
}

void Window::initialize()
{
	if (!_initialized)
	{
		glfwInit();
		//no default rendering client, we'll hook vulkan up
		//to the window later
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		//resizing breaks the swapchain, we'll disable it for now
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		_initialized = true;
	}
}

GLFWwindow* Window::getWindowObject() const
{
	return _window.get();
}
