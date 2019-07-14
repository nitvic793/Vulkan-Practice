#pragma once

#include <glm/glm.hpp>
#include <vector>
#include "Mesh.h"
#include "Texture.h"

typedef uint32_t EntityID;
const int MAX_ENTITIES = 12;
const glm::vec3 DefaultOrigin = glm::vec3(0.f, 0.f, 0.f);

struct Entity
{
	glm::vec3	Position;
	glm::vec3	Rotation;
	glm::vec3	Scale;
	Mesh		MeshModel;
	TextureID	TextureID;
};


class EntityManager
{
public:
	EntityManager();
	void							UpdateWorldMatrices();
	EntityID						CreateEntity(const Mesh& mesh, TextureID textureID, glm::vec3 position = DefaultOrigin);
	void							Move(EntityID id, const glm::vec3& offset);
	void							SetPosition(const EntityID& id, const glm::vec3& position);
	void							SetRotation(const EntityID& id, const glm::vec3& rotation);
	const std::vector<glm::mat4>&	GetWorldMatrices();
	const std::vector<Entity>&		GetEntities();
	const glm::vec3&				GetPosition(EntityID id);
private:
	std::vector<Entity> entities;
	std::vector<glm::mat4> worlds;

	uint32_t currentEntityIndex;
};

