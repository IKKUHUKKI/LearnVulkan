#include "Window.h"
#include <iostream>
int main()
{
	auto parameters = std::unique_ptr<WindowParameters>(new WindowParameters({ 600, 400, "Test Window"}));
	Window* window = new Window(std::move(parameters));

	
	delete window;
	return 0;
}