#pragma once

#include "WindowParameters.h"
#include "GLFWwindowDeleter.h"

#include <GLFW/glfw3.h>
#include <memory>

class Window
{
public:
	~Window();
	
	Window(std::unique_ptr<WindowParameters> parameters);

	GLFWwindow* getWindowObject() const;

	void initialize();

private:
	std::unique_ptr<GLFWwindow, GLFWwindowDeleter> _window{};

	bool _initialized;
};