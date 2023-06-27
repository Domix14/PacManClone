#pragma once
#include "Entity.h"

class Level :
    public Entity
{
public:
	Level(class Game* game);
	
	void loadResources(ResourceManager* resourceManager) override;
};

