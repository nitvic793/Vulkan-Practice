#pragma once

#include <glm/glm.hpp>

struct DirectionalLight
{
	alignas(16) glm::vec3 direction;
	alignas(16) glm::vec3 color;
};

struct UniformBufferObject
{
	alignas(16) glm::mat4 model;
	alignas(16) glm::mat4 view;
	alignas(16) glm::mat4 proj;
};

struct LightBuffer
{
	DirectionalLight dirLight;
};

struct PerObjectBuffer
{
	alignas(16) glm::mat4 model;
};
