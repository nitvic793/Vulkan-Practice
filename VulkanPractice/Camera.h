#pragma once

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

const glm::vec3 DefaultUp = glm::vec3(0, 1, 0);

struct Camera
{
public:
	Camera() : Projection(glm::mat4(1)) {};
	Camera(float fovInAngles, float aspect, float near = 0.1f, float far = 100.f);
	glm::mat4 Projection;
	glm::vec3 Position;
	glm::vec3 Rotation;
	glm::vec3 Direction;

	glm::mat4 GetView();
	glm::mat4 GetProjection();
};

