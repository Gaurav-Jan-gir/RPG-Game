#include "Enemy.h"

Enemy::Enemy()
{
	if (!texture.loadFromFile("./Assets/Images/enemy.png"))  throw std::runtime_error("Failed to load enemy image");
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.35f, 0.35f));
	sprite.setPosition(100, 100);
	health.setText(std::to_string(settings.getHealth()));
}
void Enemy::update(sf::Time clockTime) {
	float scale = settings.getSpeed() * clockTime.asMicroseconds() / 1000;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		sprite.move(-scale, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		sprite.move(scale, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		sprite.move(0, -scale);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		sprite.move(0, scale);
	health.setPosition(sprite.getPosition() + sf::Vector2f(0, -20));
}
	
void Enemy::draw(sf::RenderWindow &window) {
	window.draw(sprite);
	health.draw(window);
}
