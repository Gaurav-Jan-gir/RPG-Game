#pragma once
#include<SFML/Graphics.hpp>
#include "Text.h"
class PlayerSettings {
	float health;
	float speed;
public:
	PlayerSettings(float health = 100, float speed = 1.0f) {
		this->health = health;
		this->speed = speed;
	}
	inline float const getHealth() {	return health; }
	inline float const getSpeed() {	return speed; }
	void setHealth(float health) {	this->health = health; }
	void setSpeed(float speed) {  this->speed = speed; }
};
class BulletSettings {
	float speed;
	float damage;
	float fireRate;
	float bulletSize;
public:
	BulletSettings(float speed = 1.0f, float damage = 10.0f, float fireRate = 10.0f, float bulletSize = 5.0f) {
		this->speed = speed;
		this->damage = damage;
		this->fireRate = fireRate;
		this->bulletSize = bulletSize;
	}
	inline float const getSpeed() { return speed; }
	inline float const getDamage() { return damage; }
	inline float const getFireRate() { return fireRate; }
	inline float const getBulletSize() { return bulletSize; }
	void setSpeed(float speed) { this->speed = speed; }
	void setDamage(float damage) { this->damage = damage; }
	void setFireRate(float fireRate) { this->fireRate = fireRate; }
	void setBulletSize(float bulletSize) { this->bulletSize = bulletSize; }
};

class EnemySettings {
	float health;
	float speed;
	sf::Int64 enemySpawnTime;
public:
	EnemySettings(float health = 100.0f, float speed = 1.0f,sf::Int64 enemySpawnTime = 1e6) {
		this->health = health;
		this->speed = speed;
		this->enemySpawnTime = enemySpawnTime;
	}
	inline int const getHealth() { return (int)health; }
	inline int const getSpeed() { return (int)speed; }
	void setHealth(float health) { this->health = health; }
	void setSpeed(float speed) { this->speed = speed; }
	inline sf::Int64 getSpawnTime() { return enemySpawnTime; }
};

class Settings
{
public:
	void setup(sf::RenderWindow& window, sf::ContextSettings& settings);
};



