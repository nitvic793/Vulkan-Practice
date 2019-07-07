#pragma once
#include "VulkanApp.h"

class Game : public VulkanApp
{
public:
	virtual void Initialize() override;
	virtual void Update(float deltaTime, float totalTime) override;
private:

};

