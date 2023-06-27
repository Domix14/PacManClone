#include "Entity.h"

Entity::Entity(Game* game) :
	m_bAlive(true),
	m_bDraw(true),
	m_bEnableCollision(false),
	m_bMovable(false),
	m_game(game) {}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_bDraw)
	{
		target.draw(m_sprite, states);
	}
}

const sf::Sprite& Entity::getSprite() const
{
	return m_sprite;
}

sf::Vector2f Entity::getPosition() const
{
	return m_sprite.getPosition();
}

void Entity::setPosition(sf::Vector2f position)
{
	m_sprite.setPosition(position);
	m_collisionRect.left = position.x + m_collisionRectOffset.x;
	m_collisionRect.top = position.y + m_collisionRectOffset.y;
}

bool Entity::isCollisionEnabled() const
{
	return m_bEnableCollision;
}

sf::FloatRect Entity::getCollisionRect() const
{
	return m_collisionRect;
}

bool Entity::isAlive() const
{
	return m_bAlive;
}

bool Entity::isMovable() const
{
	return m_bMovable;
}

void Entity::destroy()
{
	m_bAlive = false;
}

void Entity::setAlive()
{
	m_bAlive = true;
}

Game* Entity::getGame() const
{
	return m_game;
}
