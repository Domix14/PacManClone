#pragma once
#include "Entity.h"

class PowerUp :
	public Entity
{
public:
	PowerUp(class Game* game);

	virtual void loadResources(ResourceManager* resourceManager) override;
};

