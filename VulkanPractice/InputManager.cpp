#include "InputManager.h"

bool InputManager::IsKeyDown(int glKey)
{
	return (glfwGetKey(window, glKey) == GLFW_PRESS);
}

bool InputManager::IsKeyUp(int glKey)
{
	return (glfwGetKey(window, glKey) == GLFW_RELEASE);
}
