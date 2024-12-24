#pragma once
#include<SFML/Graphics.hpp>
#include "Settings.h"
class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	PlayerSettings settings;
public:
	Player();
	void update(sf::Time);
	void draw(sf::RenderWindow&);
	sf::Vector2f getPosition();
};

