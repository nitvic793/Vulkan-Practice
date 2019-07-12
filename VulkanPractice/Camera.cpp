#include "Camera.h"

Camera::Camera(float fovInAngles, float aspect, float near, float far)
{
	Projection = glm::perspective(glm::radians(fovInAngles), aspect, near, far);
	Direction = glm::normalize(glm::vec3(0, 0, -1));
}

glm::mat4 Camera::GetView()
{
	auto view = glm::lookAt(Position, Position + Direction, DefaultUp);
	return view;
}

glm::mat4 Camera::GetProjection()
{
	return Projection;
}
