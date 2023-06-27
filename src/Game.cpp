#include "Game.h"

#include "Engine.h"

Game::Game(std::size_t width, std::size_t height, const std::string& title) :
	m_windowWidth(width),
	m_windowHeight(height),
	m_title(title)
{
}

std::size_t Game::getWindowWidth() const
{
	return m_windowWidth;
}

std::size_t Game::getWindowHeight() const
{
	return m_windowHeight;
}

std::string Game::getTitle() const
{
	return m_title;
}

void Game::setEngine(Engine* engine)
{
	m_engine = engine;
}

Engine* Game::getEngine() const
{
	return m_engine;
}
