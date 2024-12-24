#include "Text.h"

Text::Text(std::string font)
{
	if (!this->font.loadFromFile(font)) throw std::runtime_error("Failed to load font");
	text.setFont(this->font);
}

void Text::draw(sf::RenderWindow& window)
{
	window.draw(text);
}

void Text::setText(std::string text)
{
	this->text.setString(text);
}

void Text::setPosition(sf::Vector2f position)
{
	this->text.setPosition(position);
}

void Text::setCharacterSize(int size)
{
	this->text.setCharacterSize(size);
}

void Text::setFillColor(sf::Color color)
{
	this->text.setFillColor(color);
}

void Text::setFont(std::string font)
{
	if (!this->font.loadFromFile(font)) throw std::runtime_error("Failed to load font");
	text.setFont(this->font);
}






