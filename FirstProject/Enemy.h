#pragma once
#include<SFML/Graphics.hpp>
#include "Settings.h"
class Enemy
{
private:
	sf::Texture* texture;
	sf::Sprite* sprite;
	EnemySettings settings;
	Text* health;
	sf::Vector2f direction;
	sf::Vector2f position;

public:
	Enemy(sf::Vector2f position = sf::Vector2f(100.f,100.f),sf::Vector2f direction = sf::Vector2f(1.0f,1.0f)/float(sqrt(2)));
	void DeletePointers();
	void update(sf::Time);
	void draw(sf::RenderWindow&);
	sf::FloatRect getRect() { return sprite->getGlobalBounds(); }
	void setHealth(float health) { settings.setHealth(health); }
	int const getHealth() { return settings.getHealth(); }
	void showHealth() { health->setText(std::to_string(settings.getHealth())); }
	sf::Int64 getSpawnTime() { return settings.getSpawnTime(); }
};



