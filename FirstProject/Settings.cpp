#include "settings.h"

void Settings::setup(sf::RenderWindow& window,sf::ContextSettings &settings) {
	settings.antialiasingLevel = 8;
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
}
