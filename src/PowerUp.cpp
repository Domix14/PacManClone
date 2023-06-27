#include "PowerUp.h"
#include "ResourceManager.h"

PowerUp::PowerUp(Game* game) :
	Entity(game)
{
	m_bEnableCollision = true;
	m_collisionRect.width = 10;
	m_collisionRect.height = 10;
	m_collisionRectOffset = { 10.f, 10.f };
}

void PowerUp::loadResources(ResourceManager* resourceManager)
{
	resourceManager->loadTexture("power_up", "resources/graphics/power_up.png");
	m_sprite.setTexture(resourceManager->getTexture("power_up"));
}