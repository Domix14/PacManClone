#pragma once

#include <iostream>
#include <SFML/System/Vector2.hpp>

#ifdef _DEBUG

static inline void log_implementation(std::string text, float value)
{
	std::cout << text << value << "\n";
}

static inline void log_implementation(std::string text, sf::Vector2f vector)
{
	std::cout << text << "x: " << vector.x << " y: " << vector.y << "\n";
}

static inline void log_implementation(std::string text)
{
	std::cout << text << "\n";
}

static inline void log_implementation(std::string text, sf::Vector2i vector)
{
	std::cout << text << "x: " << vector.x << " y: " << vector.y << "\n";
}

#define LOG(t, v) log_implementation(t, v)
#define LOGS(t) log_implementation(t)
#else
#define LOG(t, v)
#endif

int randRange(int start, int end);
float length(sf::Vector2f vector);
sf::Vector2i abs(sf::Vector2i vector);