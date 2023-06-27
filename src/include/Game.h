#pragma once

#include <string>
/*Base class for game*/

class Game
{
public:
	Game(std::size_t width, std::size_t height, const std::string& title);

	/*Launch the game*/
	virtual void launch() {}

	/*Called every frame*/
	virtual void update(float deltaTime) {}

	/*Returns window width*/
	std::size_t getWindowWidth() const;

	/*Returns window height*/
	std::size_t getWindowHeight() const;

	/*Returns game title*/
	std::string getTitle() const;

	/*Set engine pointer*/
	void setEngine(class Engine* engine);

	/*Returns engine pointer*/
	class Engine* getEngine() const;
	
private:
	std::size_t m_windowWidth;
	std::size_t m_windowHeight;
	std::string m_title;
	class Engine* m_engine;
};

