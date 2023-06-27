#pragma once
#include "Entity.h"
#include "Animation.h"
class PacMan :
    public Entity
{
public:
	PacMan(class Game* game);
	
	void loadResources(ResourceManager* resourceManager) override;
	void update(float deltaTime) override;
	void onCollision(Entity* otherEntity) override;

	/*Restart PacMan position*/
	void restart();

	/*Returns map position*/
	sf::Vector2i getMapPosition() const;

	/*Returns direction*/
	sf::Vector2i getDirection() const;
private:
	void updatePosition(float deltaTime);
	void changeAnimation();
	void processInput();
	void setDirection(sf::Vector2i newDirection);
	bool findDestination(sf::Vector2i direction);
	
	const sf::Vector2i START_POSITION;
	const sf::Vector2i START_DIRECTION;
	
	Animation m_animation;

	sf::Vector2i m_direction;
	sf::Vector2i m_mapPosition;
	sf::Vector2i m_nextDirection;
	sf::Vector2f m_destination;
	float m_movementSpeed;
};

