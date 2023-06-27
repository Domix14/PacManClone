#pragma once

#include <SFML/Graphics.hpp>

enum CollisionChannel
{
	Player = 1,
	Enemy = 2,
	World = 3,
};

class Entity : public sf::Drawable
{
public:
	Entity(class Game* game);
	virtual ~Entity() {}
	
	/*Draw function, called every frame to draw m_sprite, can be overriden*/
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	/*Called when added to engine*/
	virtual void beginPlay() {}

	/*Called every frame*/
	virtual void update(float deltaTime) {}

	/*Called when added to engine*/
	virtual void loadResources(class ResourceManager* resourceManager) {}
	
	/*Called when collision is detected*/
	virtual void onCollision(Entity* otherEntity) {}

	/*Returns sprite*/
	const sf::Sprite& getSprite() const;

	/*Returns position*/
	sf::Vector2f getPosition() const;

	/*Return true if collision is enabled*/
	bool isCollisionEnabled() const;
	
	/*Return collision rect*/
	sf::FloatRect getCollisionRect() const;

	/*Returns true if Entity can move*/
	bool isMovable() const;

	/*Set new position of entity*/
	void setPosition(sf::Vector2f position);

	/*Returns true if Entity is alive*/
	bool isAlive() const;
	
	/*Set Entity to alive state*/
	void setAlive();
	
	/*Destroy the Entity*/
	void destroy();
protected:
	class Game* getGame() const;

	bool m_bDraw;
	bool m_bEnableCollision;
	bool m_bMovable;
	
	sf::Sprite m_sprite;
	sf::Vector2f m_collisionRectOffset;
	sf::FloatRect m_collisionRect;
private:
	class Game* const m_game;

	bool m_bAlive;
};

