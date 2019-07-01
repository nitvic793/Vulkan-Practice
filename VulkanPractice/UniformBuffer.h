#pragma once

#include <glm/glm.hpp>

struct DirectionalLight
{
	glm::vec3 direction;
	glm::vec3 color;
};

struct UniformBufferObject
{
	alignas(16) glm::mat4 model;
	alignas(16) glm::mat4 view;
	alignas(16) glm::mat4 proj;
};

struct LightBuffer
{
	alignas(16) DirectionalLight dirLight;
};

struct PerObjectBuffer
{
	alignas(16) glm::mat4 model;
};
