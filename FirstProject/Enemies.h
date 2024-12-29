#pragma once
#include "Enemy.h"
#include "Bullets.h"
class Enemies
{
	std::vector<Enemy> enemies;
public:
	Enemies();
	void update(sf::Time& clockTime,sf::Int64& enemySpawnCounter,Bullets& bullets, sf::Vector2f targetPosition, sf::Vector2u screenSize);
	void draw(sf::RenderWindow& window);
	void load(sf::Vector2f targetPosition, sf::Vector2u screenSize);
	sf::Vector2f setSpawnPosition(sf::Vector2u screenSize);
};

