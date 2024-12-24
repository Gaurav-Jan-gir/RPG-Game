#pragma once
#include "Player.h"
class Bullet
{
private:
	sf::Vector2f position;
	sf::Vector2f direction;
	BulletSettings settings;
	sf::ConvexShape shape;
public:
	Bullet(Player& player,sf::RenderWindow& );
	Bullet();
	sf::Vector2f getPosition();
	sf::Vector2f getDirection();
	inline float const getSpeed() { return settings.getSpeed(); }
	inline float const getDamage() { return settings.getDamage(); }
	inline sf::FloatRect getRect() { return shape.getGlobalBounds(); }
	void update(sf::Time&);
	void draw(sf::RenderWindow& window) { window.draw(shape); }
private:
	sf::Vector2f launchPosition();
	sf::Vector2f launchDirection(sf::RenderWindow&);
};

