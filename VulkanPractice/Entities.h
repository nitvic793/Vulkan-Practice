#pragma once

#include <glm/glm.hpp>
#include <vector>

typedef uint32_t EntityID;
const int MAX_ENTITIES = 12;
const glm::vec3 DefaultOrigin = glm::vec3(0.f, 0.f, 0.f);

struct Entity
{
	glm::vec3 Position;
};


class EntityManager
{
public:
	EntityManager();
	void		UpdateWorldMatrices();
	EntityID	CreateEntity(glm::vec3 position = DefaultOrigin);
	void		SetPosition(const EntityID& id, const glm::vec3& position);
private:
	std::vector<Entity> entities;
	std::vector<glm::mat4> worlds;

	uint32_t currentEntityIndex;
};

