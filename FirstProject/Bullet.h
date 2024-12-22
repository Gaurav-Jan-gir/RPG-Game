#pragma once
#include "Player.h"
class Bullet
{
private:
	sf::Vector2f position;
	sf::Vector2f direction;
public:
	float speed = 0;
	sf::ConvexShape shape;
public:
	Bullet(Player& player,float speed=1.f);
	sf::Vector2f getPosition();
	sf::Vector2f getDirection();
private:
	sf::Vector2f launchPosition();
	sf::Vector2f launchDirection();
};

