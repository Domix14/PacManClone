#include "ResourceManager.h"

#include <iostream>

void ResourceManager::loadTexture(const std::string& textureName, const std::string& texturePath)
{
	if (m_textures.find(textureName) != m_textures.end()) return;
	
	sf::Texture newTexture;
	if(newTexture.loadFromFile(texturePath))
	{
		m_textures[textureName] = newTexture;
	}
	else
	{
		std::cout << "Failed to find texture";
	}
}

const sf::Texture& ResourceManager::getTexture(const std::string& textureName)
{
	if(m_textures.find(textureName) != m_textures.end())
	{
		return m_textures[textureName];
	}
	else
	{
		return m_textures[textureName] = sf::Texture();
	}
}

void ResourceManager::loadFont(const std::string& fontName, const std::string& fontPath)
{
	if (m_fonts.find(fontName) != m_fonts.end()) return;
	
	sf::Font newFont;
	if (newFont.loadFromFile(fontPath))
	{
		m_fonts[fontName] = newFont;
	}
	else
	{
		std::cout << "Failed to find font";
	}
}

const sf::Font& ResourceManager::getFont(const std::string& fontName)
{
	if (m_fonts.find(fontName) != m_fonts.end())
	{
		return m_fonts[fontName];
	}
	else
	{
		return m_fonts[fontName] = sf::Font();
	}
}
