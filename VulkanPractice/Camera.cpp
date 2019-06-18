#include "Camera.h"

Camera::Camera(float fovInAngles, float aspect, float near, float far)
{
	Projection = glm::perspective(glm::radians(fovInAngles), aspect, near, far);
}

glm::mat4 Camera::GetView()
{
	auto view = glm::lookAt(Position, glm::vec3(0, 0, 0), glm::vec3(0.f, 1.f, 0.f));
	return view;
}

glm::mat4 Camera::GetProjection()
{
	return Projection;
}
