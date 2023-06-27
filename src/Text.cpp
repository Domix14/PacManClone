#include "Text.h"

#include "ResourceManager.h"

Text::Text(Game* game, unsigned fontSize, sf::Vector2f position) :
	Entity(game)
{
	m_text.setCharacterSize(fontSize);
	m_text.setPosition(position);
}

void Text::loadResources(ResourceManager* resourceManager)
{
	resourceManager->loadFont("font", "resources/fonts/font.otf");
	m_text.setFont(resourceManager->getFont("font"));
}

void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_text, states);
}

void Text::setText(const std::string& newText)
{
	m_text.setString(newText);
}
