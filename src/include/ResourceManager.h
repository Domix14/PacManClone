#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

#include <unordered_map>
#include <string>



class ResourceManager
{
public:
	/*Loads texture from file*/
	void loadTexture(const std::string& textureName, const std::string& texturePath);

	/*Returns texture*/
	const sf::Texture& getTexture(const std::string& textureName);

	/*Load font from file*/
	void loadFont(const std::string& fontName, const std::string& fontPath);

	/*Returns font*/
	const sf::Font& getFont(const std::string& fontName);
private:
	std::unordered_map<std::string, sf::Texture> m_textures;
	std::unordered_map<std::string, sf::Font> m_fonts;
};

