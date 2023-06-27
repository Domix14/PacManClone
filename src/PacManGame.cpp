#include "PacManGame.h"

#include "Map.h"
#include "Engine.h"

#include <fstream>

PacManGame::PacManGame() :
	Game(WINDOW_WIDTH, WINDOW_HEIGHT, "Pac-Man"),
	m_currentLevel(0),
	m_menu(this),
	m_pacMan(this),
	m_blinky(this, &m_pacMan),
	m_pinky(this, &m_pacMan),
	m_clyde(this, &m_pacMan),
	m_inky(this, &m_pacMan, &m_blinky),
	m_level(this),
	m_scoreText(this, 20, sf::Vector2f(0.f, 0.f)),
	m_livesText(this, 20, sf::Vector2f(550.f, 0.f)),
	m_score(0)
{
	m_statesProperties[NewGame].emplace_back(0.f, 0, 1, GameState::Scatter, GhostState::Scatter);
	m_statesProperties[Scatter].emplace_back(10.f, 0, 1, GameState::Chase, GhostState::Scatter);
	m_statesProperties[Chase].emplace_back(20.f, 0, 1, GameState::Scatter, GhostState::Chase);
}

void PacManGame::launch()
{
	loadScore();
	openMenu();
}

void PacManGame::update(float deltaTime)
{
	updateState(deltaTime);
}

void PacManGame::exit()
{
	getEngine()->close();
}

void PacManGame::openMenu()
{
	getEngine()->addEntity(&m_menu);
	m_menu.setBestScore(m_bestScore);
}

void PacManGame::closeGame()
{
	m_level.destroy();
	m_livesText.destroy();
	m_blinky.destroy();
	m_scoreText.destroy();
	m_pacMan.destroy();
	m_pinky.destroy();
	m_clyde.destroy();
	m_inky.destroy();

	for (auto& c : m_coins)
	{
		c.destroy();
	}

	for (auto& p : m_powers)
	{
		p.destroy();
	}
}

void PacManGame::startGame()
{
	m_menu.destroy();

	getEngine()->addEntity(&m_level);
	getEngine()->addEntity(&m_scoreText);
	getEngine()->addEntity(&m_livesText);
	getEngine()->addEntity(&m_pacMan);
	getEngine()->addEntity(&m_blinky);
	getEngine()->addEntity(&m_pinky);
	getEngine()->addEntity(&m_clyde);
	getEngine()->addEntity(&m_inky);
	spawnCoins();

	resetGame();
}

void PacManGame::spawnCoins()
{
	m_coins.reserve(40);
	for(std::size_t x = 0;x < getMapMaxColumnIndex();x++)
	{
		for(std::size_t y = 0;y < getMapMaxRowIndex();y++)
		{
			if(map[y][x] == MapType::Move)
			{
				m_coins.emplace_back(this);
				m_coins.back().setPosition(getMapOffset() + sf::Vector2f(x * BLOCK_WIDTH, y * BLOCK_WIDTH));
			}
			else if(map[y][x] == MapType::PowerUpPosition)
			{
				m_powers.emplace_back(this);
				m_powers.back().setPosition(getMapOffset() + sf::Vector2f(x * BLOCK_WIDTH, y * BLOCK_WIDTH));
			}
		}
	}

	for(auto& coin : m_coins)
	{
		getEngine()->addEntity(&coin);
	}

	for (auto& Power : m_powers)
	{
		getEngine()->addEntity(&Power);
	}
}

void PacManGame::addScore(std::size_t score)
{
	m_score += score;
	m_scoreText.setText("Score: " + std::to_string(m_score));
}

void PacManGame::killPacMan()
{
	m_lives--;
	m_livesText.setText("Lives: " + std::to_string(m_lives));
	if(m_lives < 0)
	{
		if(m_score > m_bestScore)
		{
			m_bestScore = m_score;
			saveScore();
		}
		resetGame();
		openMenu();
		closeGame();
	}
	else
	{
		resetPositions();
	}
}

void PacManGame::resetPositions()
{
	m_pacMan.restart();
	m_blinky.restart();
	m_pinky.restart();
	m_inky.restart();
	m_clyde.restart();
	changeState(GameState::NewGame);
}

void PacManGame::resetGame()
{
	m_lives = 1;
	resetLevel();
	m_livesText.setText("Lives: " + std::to_string(m_lives));
	m_scoreText.setText("Score: " + std::to_string(m_score));
}

void PacManGame::resetLevel()
{
	resetPositions();
	m_coinCount = 219;
}

void PacManGame::changeState(GameState state)
{
	auto& properties = m_statesProperties[state];
	for(auto& p : properties)
	{
		if(p.firstLevel <= m_currentLevel && p.lastLevel >= m_currentLevel)
		{
			m_state = state;
			m_stateTimer = p.duration;
			m_blinky.changeGlobalState(p.ghostState);
			m_pinky.changeGlobalState(p.ghostState);
			m_inky.changeGlobalState(p.ghostState);
			m_clyde.changeGlobalState(p.ghostState);
		}
	}
}

void PacManGame::updateState(float deltaTime)
{
	m_stateTimer -= deltaTime;
	if(m_stateTimer <= 0.f)
	{
		auto& properties = m_statesProperties[m_state];
		for (auto& p : properties)
		{
			if (p.firstLevel <= m_currentLevel && p.lastLevel >= m_currentLevel)
			{
				changeState(p.nextState);
			}
		}
	}
}

void PacManGame::pickCoin()
{
	addScore(10);
	m_coinCount--;
	if(m_coinCount == 0)
	{
		resetLevel();
	}
}

void PacManGame::pickPowerUp()
{
	addScore(10);
	m_blinky.changeState(GhostState::Frightened);
	m_pinky.changeState(GhostState::Frightened);
	m_inky.changeState(GhostState::Frightened);
	m_clyde.changeState(GhostState::Frightened);
}

void PacManGame::saveScore() const
{
	std::ofstream file("best_score.txt");
	if (file.is_open())
	{
		file << m_bestScore;
		file.close();
	}
}

void PacManGame::loadScore()
{
	std::ifstream file("best_score.txt");
	if (file.is_open())
	{
		file >> m_bestScore;
		file.close();
	}
	else 
	{
		m_bestScore = 0;
	}

}
