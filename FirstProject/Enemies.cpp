#include "Enemies.h"
#include "Bullets.h"

Enemies::Enemies()
{
}

void Enemies::update(sf::Time& clockTime,sf::Int64& enemySpawnCounter,Bullets& bullets,sf::Vector2f targetPosition, sf::Vector2u screenSize)
{
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].update(clockTime);
		bullets.checkCollision(enemies[i]);
		if (enemies[i].getHealth() <= 0)
			//enemies[i].DeletePointers();
			enemies.erase(enemies.begin() + i);
	}
	sf::Int64 delay = 1000000;
	if(!enemies.empty())
		delay = enemies[0].getSpawnTime();
	if (enemySpawnCounter > delay)
	{
		load(targetPosition,screenSize);
		enemySpawnCounter = 0;
	}
	enemySpawnCounter += clockTime.asMicroseconds();
}

void Enemies::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].draw(window);
	}
}

void Enemies::load(sf::Vector2f targetPosition,sf::Vector2u screenSize)
{
	sf::Vector2f position = setSpawnPosition(screenSize);
	sf::Vector2f direction = targetPosition - position;
	double length = sqrt(direction.x * direction.x + direction.y * direction.y);
	while (length <= 200) {
		position = setSpawnPosition(screenSize);
		direction = targetPosition - position;
		length = sqrt(direction.x * direction.x + direction.y * direction.y);
	}
	direction = direction / float(length);
	Enemy enemy(position, direction);
	enemies.push_back(enemy);
}

sf::Vector2f Enemies::setSpawnPosition(sf::Vector2u screenSize)
{
	sf::Vector2f pos;
	int num = rand() % 4;
	switch (num)
	{
	case 0:
		pos.x = 100 - rand() % 100;
		pos.y = rand() % screenSize.y;
		break;
	case 1:
		pos.x = rand() % screenSize.x;
		pos.y = 100 - rand() % 100;
		break;
	case 2:
		pos.x = screenSize.x - 100 + rand() % 100;
		pos.y = rand() % screenSize.y;
		break;
	case 3:
		pos.x = rand() % screenSize.x;
		pos.y = screenSize.y - 100 + rand() % 100;
		break;
	default:
		break;
	}
	return pos;
}