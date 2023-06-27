#include "Menu.h"
#include "ResourceManager.h"
#include "Map.h"
#include "PacManGame.h"

#include <fstream>

Menu::Menu(Game* game) :
	Entity(game),
	m_keyPressed(false),
	m_currentText(0)
{
	m_logoSprite.setPosition(sf::Vector2f(140.f, 100.f));
	m_bestScoreText.setCharacterSize(40);
	m_bestScoreText.setPosition(sf::Vector2f(220.f, 350.f));
	m_bestScoreText.setString("Best score: 0");
	
	m_menuTexts[0].setPosition(sf::Vector2f(250.f, 500.f));
	m_menuTexts[0].setString("Start");
	m_menuTexts[0].setCharacterSize(70);
	m_menuTexts[0].setFillColor(sf::Color::Red);

	m_menuTexts[1].setPosition(sf::Vector2f(266.f, 600.f));
	m_menuTexts[1].setString("Exit");
	m_menuTexts[1].setCharacterSize(70);

}

void Menu::update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !m_keyPressed)
	{
		m_menuTexts[m_currentText].setFillColor(sf::Color::White);
		m_currentText = ((--m_currentText) + m_menuTexts.size()) % m_menuTexts.size();
		m_menuTexts[m_currentText].setFillColor(sf::Color::Red);
		m_keyPressed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !m_keyPressed)
	{
		m_menuTexts[m_currentText].setFillColor(sf::Color::White);
		m_currentText = (++m_currentText) % m_menuTexts.size();
		m_menuTexts[m_currentText].setFillColor(sf::Color::Red);
		m_keyPressed = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_keyPressed)
	{
		m_keyPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		auto game = dynamic_cast<PacManGame*>(getGame());
		switch (m_currentText)
		{
		case 0:
			game->startGame();
			break;
		case 1:
			game->exit();
			break;
		}
	}
}

void Menu::loadResources(ResourceManager* resourceManager)
{
	resourceManager->loadTexture("logo", "resources/graphics/logo.png");
	m_logoSprite.setTexture(resourceManager->getTexture("logo"));

	resourceManager->loadFont("font", "resources/fonts/font.otf");
	m_menuTexts[0].setFont(resourceManager->getFont("font"));
	m_menuTexts[1].setFont(resourceManager->getFont("font"));
	m_bestScoreText.setFont(resourceManager->getFont("font"));
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_logoSprite, states);
	target.draw(m_bestScoreText, states);
	target.draw(m_menuTexts[0], states);
	target.draw(m_menuTexts[1], states);
}

void Menu::setBestScore(std::size_t score)
{
	m_bestScoreText.setString("Best score: " + std::to_string(score));
}
