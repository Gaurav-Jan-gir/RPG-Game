#include "Enemy.h"

Enemy::Enemy(sf::Vector2f pos,sf::Vector2f dir)
{
	texture = new sf::Texture();
	if (!texture->loadFromFile("./Assets/Images/enemy.png"))  throw std::runtime_error("Failed to load enemy image");
	sprite = new sf::Sprite();
	sprite->setTexture(*texture);
	sprite->scale(sf::Vector2f(0.35f, 0.35f));
	position = pos;
	sprite->setPosition(position);
	direction = dir;
	health = new Text();
	health->setText(std::to_string(settings.getHealth()));
}

void Enemy::DeletePointers()
{
	delete texture;
	delete sprite;
	delete health;
}

void Enemy::update(sf::Time clockTime) {
	sprite->move((direction * float(settings.getSpeed())) * float(clockTime.asMicroseconds() / 10000));
    health->setPosition(sf::Vector2f(sprite->getPosition().x, sprite->getPosition().y - 10));
}
	
void Enemy::draw(sf::RenderWindow &window) {
	if(sprite)
	window.draw(*sprite);
	health->draw(window);
}
