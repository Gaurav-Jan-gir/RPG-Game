#include "Bullets.h"

void Bullets::load(Player& player)
{
	Bullet newBullet(player);
	if (std::abs(newBullet.getDirection().x) > 0.5f || std::abs(newBullet.getDirection().y) > 0.5f)
		bullets.push_back(newBullet);	
}

void Bullets::update()
{		
	for (Bullet &bullet : bullets)
		bullet.shape.move(bullet.getDirection() * bullet.speed);
}

void Bullets::draw(sf::RenderWindow& window)
{
	for (Bullet &bullet : bullets)
		window.draw(bullet.shape);
}


