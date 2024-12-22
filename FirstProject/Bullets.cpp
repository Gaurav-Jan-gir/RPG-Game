#include "Bullets.h"

void Bullets::load(Player& player)
{
	Bullet newBullet(player);
	if (newBullet.getDirection().x > 0.5f || newBullet.getDirection().y > 0.5f)
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


