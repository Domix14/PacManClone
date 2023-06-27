#include "Coin.h"

#include "ResourceManager.h"

Coin::Coin(Game* game) :
	Entity(game)
{
	m_bEnableCollision = true;
	m_collisionRect.width = 10.f;
	m_collisionRect.height = 10.f;
	m_collisionRectOffset = { 10.f, 10.f };
}

void Coin::loadResources(ResourceManager* resourceManager)
{
	resourceManager->loadTexture("coin", "resources/graphics/coin.png");
	m_sprite.setTexture(resourceManager->getTexture("coin"));
}
