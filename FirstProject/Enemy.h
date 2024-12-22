#pragma once
#include<SFML/Graphics.hpp>
class Enemy
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Enemy();
	void update();
	void draw(sf::RenderWindow& window);
};

