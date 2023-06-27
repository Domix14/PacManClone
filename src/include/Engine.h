#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "ResourceManager.h"

class Engine :
    public sf::RenderWindow
{
public:
	Engine(class Game* game);

	/*Starts the engine*/
	void start();

	/*Returns delta */
	float getDeltaTime() const;

	/*Add entity*/
	void addEntity(Entity* entity);

	/*Returns resource manager*/
	const ResourceManager* getResourceManager() const;
	
private:
	float resetClock();
	void updateEntities(float deltaTime);
	void drawEntities();
	void checkEntitiesCollisions();
	void checkForDestroyedEntities();
	
	class Game* m_game;
	
	sf::Clock m_frameClock;
	
	std::vector<Entity*> m_entities;

	ResourceManager m_resourceManager;
};

