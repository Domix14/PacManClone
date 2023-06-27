#pragma once
#include "Entity.h"
class Coin :
    public Entity
{
public:
	Coin(class Game* game);

	void loadResources(ResourceManager* resourceManager) override;
};

 