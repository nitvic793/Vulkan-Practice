#pragma once

#include <GLFW/glfw3.h>

class InputManager
{
public:
	inline void SetWindow(GLFWwindow* glWindow) { window = glWindow; };

	bool IsKeyDown(int glKey);
	bool IsKeyUp(int glKey);
private:
	GLFWwindow* window;

};

