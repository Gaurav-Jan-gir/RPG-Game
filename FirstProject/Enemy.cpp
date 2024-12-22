#include "Enemy.h"

Enemy::Enemy()
{
	if (!texture.loadFromFile("./Assets/enemy.png"))  throw std::runtime_error("Failed to load enemy image");
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.35, 0.35));
	sprite.setPosition(100, 100);
}
void Enemy::update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		sprite.move(-1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		sprite.move(1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		sprite.move(0, -1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		sprite.move(0, 1);
}
	
void Enemy::draw(sf::RenderWindow &window) {
	window.draw(sprite);
}
