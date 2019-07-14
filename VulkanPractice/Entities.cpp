#include "Entities.h"
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_LEFT_HANDED

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

const glm::vec3 DefaultScale = glm::vec3(1.f, 1.f, 1.f);
const glm::vec3 DefaultRotation = glm::vec3(0.f, 0.f, 0.f);
const glm::vec3 DefaultUp = glm::vec3(0.f, 1.f, 0.f);

glm::mat4 GetWorldMatrix(const Entity& entity, const glm::mat4& world  = glm::mat4(1))
{
	auto identity = glm::mat4(1);
	auto translation = glm::translate(identity, entity.Position);
	auto rotation = glm::eulerAngleXYZ(entity.Rotation.x, entity.Rotation.y, entity.Rotation.z);
	auto scale = glm::scale(identity, entity.Scale);
	auto transform = translation * rotation * scale;
	return transform;
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

EntityID EntityManager::CreateEntity(const Mesh& mesh, TextureID textureID, glm::vec3 position)
{
	EntityID entityID = currentEntityIndex;
	entities.push_back({ position, DefaultRotation, DefaultScale, mesh, textureID });
	worlds.push_back(GetWorldMatrix(entities[entityID]));
	currentEntityIndex++;
	return entityID;
}

void EntityManager::Move(EntityID id, const glm::vec3& offset)
{
	entities[id].Position += offset;
}

void EntityManager::SetPosition(const EntityID& id, const glm::vec3& position)
{
	entities[id].Position = position;
}

void EntityManager::SetRotation(const EntityID& id, const glm::vec3& rotation)
{
	entities[id].Rotation = rotation;
}

const std::vector<glm::mat4>& EntityManager::GetWorldMatrices()
{
	return worlds;
}

const std::vector<Entity>& EntityManager::GetEntities()
{
	return entities;
}

const glm::vec3& EntityManager::GetPosition(EntityID id)
{
	return entities[id].Position;
}
