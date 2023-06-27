#pragma once

#include "SFML/Graphics.hpp"
#include <unordered_map>

class Animation
{
public:
	Animation();

	/*Update animation, should be called every frame*/
	void update(float deltaTime, sf::Sprite& sprite);

	/*Set how long one frame is displayed*/
	void setFrameTime(float time);

	/*Add animation frame from texture*/
	void addRects(const std::string& name, const std::vector<sf::IntRect>& rects);

	/*Set current animation frames*/
	void setAnimation(const std::string& name, sf::Sprite& sprite);
private:
	void nextFrame();

	std::string currentAnimation;
	std::unordered_map<std::string, std::vector<sf::IntRect>> m_textureRects;
	float m_timer;
	float m_frameTime;
	std::size_t m_frame;
	
};

