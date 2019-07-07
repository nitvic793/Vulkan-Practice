#include "Game.h"

void Game::Initialize()
{
	entities.CreateEntity();
}

void Game::Update(float deltaTime, float totalTime)
{
	entities.SetPosition(0, glm::vec3(0, sin(totalTime), 0));
}
