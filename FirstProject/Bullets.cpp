#include "Bullets.h"

void Bullets::load(Player& player,sf::RenderWindow& window,sf::Time& clockTime , sf::Int64& measure)
{
	measure += clockTime.asMicroseconds();
	if (measure < 1e6 / settings.getFireRate()) {
		return;
	}
		
	Bullet newBullet(player,window);
	if (std::abs(newBullet.getDirection().x) > 0.1f || std::abs(newBullet.getDirection().y) > 0.1f)
		bullets.push_back(newBullet);	
	measure = 0;
}

void Bullets::update(sf::Time& clockTime,Enemy& enemy)
{		
	for (size_t i = 0;i < bullets.size();i++) {
		bullets[i].update(clockTime);
		if (bullets[i].getRect().intersects(enemy.getRect())) {
			enemy.setHealth(enemy.getHealth() - bullets[i].getDamage());
			bullets.erase(bullets.begin() + i);
			enemy.showHealth();
		}
		else if (bullets[i].getRect().left < 0 || bullets[i].getRect().left > 1920 || bullets[i].getRect().top < 0 || bullets[i].getRect().top > 1080)
			bullets.erase(bullets.begin() + i);
	}
}

void Bullets::draw(sf::RenderWindow& window)
{
	for (Bullet &bullet : bullets)
		bullet.draw(window);
}


