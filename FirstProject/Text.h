#pragma once
#include <SFML/Graphics.hpp>
class Text
{
	sf::Text text;
	sf::Font font;
public:
	Text(std::string font = "./Assets/Fonts/RobotoMono-VariableFont_wght.ttf");
	void draw(sf::RenderWindow& window);
	void setText(std::string text);
	void setPosition(sf::Vector2f position);
	void setCharacterSize(int size);
	void setFillColor(sf::Color color);
	void setFont(std::string font);
	
};

