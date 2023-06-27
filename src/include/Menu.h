#pragma once
#include "Entity.h"
#include <array>
class Menu :
    public Entity
{
public:
	Menu(class Game* game);

	void update(float deltaTime) override;
	void loadResources(ResourceManager* resourceManager) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	/*Set score showed on screen*/
	void setBestScore(std::size_t score);
private:
	sf::Sprite m_logoSprite;
	sf::Text m_startText;
	sf::Text m_exitText;
	sf::Text m_bestScoreText;
	std::array<sf::Text, 2> m_menuTexts;
	bool m_keyPressed;
	std::size_t m_currentText;
};

