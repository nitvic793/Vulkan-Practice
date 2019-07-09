#include "Game.h"

void Game::Initialize()
{
	entities.CreateEntity();
	entities.CreateEntity();
}

void Game::Update(float deltaTime, float totalTime)
{
	const float speed = 0.2f;
	entities.SetPosition(0, glm::vec3(0, sin(totalTime) * speed, 0));
	entities.SetPosition(1, glm::vec3(1, sin(totalTime) * speed, 0));
	entities.SetRotation(1, glm::vec3(0, totalTime * glm::radians(90.f) * speed, 0));
}
