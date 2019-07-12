#include "Game.h"

void Game::Initialize()
{
	auto texID = AddTexture(TEXTURE_PATH);
	auto mesh = AddMesh(MODEL_PATH);
	entities.CreateEntity(mesh, texID);

	mesh = AddMesh("Models/sphere.obj");
	texID = AddTexture("Textures/texture.jpg");
	entities.CreateEntity(mesh, texID);
	AddTexture(TEXTURE_PATH);
	entities.CreateEntity(mesh, texID);
}

void Game::Update(float deltaTime, float totalTime)
{
	const float speed = 0.5f;
	float horizontal = 0.f;
	float vertical = 0.f;
	if (input.IsKeyDown(GLFW_KEY_LEFT))
	{
		horizontal = -1.f;
	}

	if (input.IsKeyDown(GLFW_KEY_RIGHT))
	{
		horizontal = 1.f;
	}

	if (input.IsKeyDown(GLFW_KEY_UP))
	{
		vertical = 1.f;
	}

	if (input.IsKeyDown(GLFW_KEY_DOWN))
	{
		vertical = -1.f;
	}

	entities.Move(0, glm::vec3(horizontal * deltaTime, vertical * deltaTime, 0.f));

	entities.SetPosition(2, glm::vec3(-1, sin(totalTime) * speed, 0));
	entities.SetPosition(1, glm::vec3(1, sin(totalTime) * speed, 0));
	entities.SetRotation(1, glm::vec3(0, totalTime * glm::radians(90.f) * speed, 0));
}
