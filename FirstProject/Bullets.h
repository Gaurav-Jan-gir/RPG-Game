#pragma once
#include "Bullet.h"

class Bullets
{
private:
	std::vector<Bullet> bullets;
public:
	void load(Player &player);
	void update();
	void draw(sf::RenderWindow& window);
};

