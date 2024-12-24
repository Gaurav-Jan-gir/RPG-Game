#pragma once
#include "Bullet.h"
#include "Enemy.h"

class Bullets
{
private:
	std::vector<Bullet> bullets;
	BulletSettings settings;
public:
	void load(Player &,sf::RenderWindow&,sf::Time&,sf::Int64&);
	void update(sf::Time&,Enemy&);
	void draw(sf::RenderWindow&);
};

