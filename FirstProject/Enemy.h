#pragma once
#include<SFML/Graphics.hpp>
#include "Settings.h"
class Enemy
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	EnemySettings settings;
	Text health;

public:
	Enemy();
	void update(sf::Time);
	void draw(sf::RenderWindow&);
	sf::FloatRect getRect() { return sprite.getGlobalBounds(); }
	void setHealth(float health) { settings.setHealth(health); }
	int const getHealth() { return settings.getHealth(); }
	void showHealth() { health.setText(std::to_string(settings.getHealth())); }
};



