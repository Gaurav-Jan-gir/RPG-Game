#include "Bullet.h"

Bullet::Bullet(Player& player,float s) {
	shape.setPointCount(5);
	shape.setPoint(0, sf::Vector2f(0, 0));
	shape.setPoint(1, sf::Vector2f(0, 8));
	shape.setPoint(2, sf::Vector2f(16, 8));
	shape.setPoint(3, sf::Vector2f(24, 4));
	shape.setPoint(4, sf::Vector2f(16, 0));
	shape.setFillColor(sf::Color::Yellow);
	shape.setOrigin(12, 4);
	position = player.getPosition() + launchPosition();
	shape.setPosition(position);
	direction = launchDirection();
	shape.setRotation(atan2(direction.y, direction.x) * 180 / 3.14159265);
	speed = s;
}

sf::Vector2f Bullet::launchPosition() {
	return sf::Vector2f(32,16);
}

sf::Vector2f Bullet::launchDirection() {
	sf::Vector2f dir(0.f, 0.f);

    // Aggregate directional input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) dir.y -= 1; // Up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) dir.y += 1; // Down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) dir.x -= 1; // Left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) dir.x += 1; // Right

    // Normalize the vector if it's non-zero
    float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    if (length > 0.f) {
        dir /= length;
    }

    return dir;
}

sf::Vector2f Bullet::getPosition() {
	return position;
}
sf::Vector2f Bullet::getDirection() {
	return direction;
}

