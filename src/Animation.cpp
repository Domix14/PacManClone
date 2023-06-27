#include "Animation.h"

#include "Utilities.h"
Animation::Animation() :
	m_timer(0.f),
	m_frameTime(0.f),
	m_frame(0),
	currentAnimation("")
{
}

void Animation::update(float deltaTime, sf::Sprite& sprite)
{
	if (m_frameTime <= 1e-8) return;

	m_timer -= deltaTime;
	if(m_timer <= 0.f)
	{
		nextFrame();
		if (m_textureRects.find(currentAnimation) != m_textureRects.end())
		{
			sprite.setTextureRect(m_textureRects[currentAnimation][m_frame]);
		}
		m_timer = m_frameTime;
	}
}

void Animation::setFrameTime(float time)
{
	m_frameTime = time;
}

void Animation::addRects(const std::string& name, const std::vector<sf::IntRect>& rects)
{
	m_textureRects[name] = rects;
}

void Animation::setAnimation(const std::string& name, sf::Sprite& sprite)
{
	if (m_textureRects.find(name) != m_textureRects.end())
	{
		currentAnimation = name;
		sprite.setTextureRect(m_textureRects[currentAnimation][m_frame]);
	}
}

void Animation::nextFrame()
{
	if(m_frame == m_textureRects[currentAnimation].size() - 1)
	{
		m_frame = 0;
	}
	else
	{
		m_frame++;
	}
}
