#include "Player.h"

Player::Player()
{
	if (!texture.loadFromFile("./Assets/Images/player.png"))  throw std::runtime_error("Failed to load player image");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(32, 0, 70, 84));
	sprite.scale(sf::Vector2f(0.5, 0.5));
}

void Player::update(sf::Time clockTime) {
	float scale = settings.getSpeed() * clockTime.asMicroseconds() / 1000;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		sprite.move(-scale, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		sprite.move(scale, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		sprite.move(0, -scale);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		sprite.move(0, scale);
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

sf::Vector2f Player::getPosition() {
	return sprite.getPosition() + sf::Vector2f(sprite.getScale().x, sprite.getScale().y / 2);
}
