#include "Entities.h"
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_LEFT_HANDED

#include <glm/gtc/matrix_transform.hpp>

glm::mat4 GetWorldMatrix(const Entity& entity, const glm::mat4& world  = glm::mat4(1))
{
	auto translation = glm::translate(world, entity.Position);
	return translation;
}

EntityManager::EntityManager():
	currentEntityIndex(0)
{
	entities.reserve(MAX_ENTITIES);
	worlds.reserve(MAX_ENTITIES);
}

void EntityManager::UpdateWorldMatrices()
{
	for (size_t i = 0; i < currentEntityIndex; ++i)
	{
		worlds[i] = GetWorldMatrix(entities[i], worlds[i]);
	}
}

EntityID EntityManager::CreateEntity(glm::vec3 position)
{
	EntityID entityID = currentEntityIndex;
	entities.push_back({ position });
	worlds.push_back(GetWorldMatrix(entities[entityID]));
	currentEntityIndex++;
	return entityID;
}

void EntityManager::SetPosition(const EntityID& id, const glm::vec3& position)
{
	entities[id].Position = position;
}
