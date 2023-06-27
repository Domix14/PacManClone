#pragma once
#include "Entity.h"
class Text :
    public Entity
{
public:
	Text(Game* game, unsigned fontSize, sf::Vector2f position);
	
	void loadResources(ResourceManager* resourceManager) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	/*Set displayed text*/
	void setText(const std::string& newText);
private:
	sf::Text m_text;
};

