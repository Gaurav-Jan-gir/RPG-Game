#pragma once
#include "Settings.h"
#include "Enemy.h"
#include "Bullets.h"
#include "Text.h"
#include "Enemies.h"

int main()
{
    sf::ContextSettings setting;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Default, setting);
	Settings settings;
	settings.setup(window, setting);

	sf::Vector2u windowSize = window.getSize();

	Player player;
	Enemies enemies;
	Bullets bullets;
	Text text;

	sf::Clock clock;

	sf::Int64 intTime=100000;
	sf::Int64 fireRateTime = 0;
	sf::Int64 enemySpawnCounter = 0;

    while (window.isOpen())
    {
		sf::Time clockTime = clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		clock.restart();
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
		bool caseI = sf::Keyboard::isKeyPressed(sf::Keyboard::I);
		bool caseJ = sf::Keyboard::isKeyPressed(sf::Keyboard::J);
		bool caseK = sf::Keyboard::isKeyPressed(sf::Keyboard::K);
		bool caseL = sf::Keyboard::isKeyPressed(sf::Keyboard::L);
		bool caseMouse = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		if (caseI || caseJ || caseK || caseL || caseMouse)
			bullets.load(player,window,clockTime,fireRateTime);
		player.update(clockTime);
		enemies.update(clockTime, enemySpawnCounter,bullets,player.getPosition(),window.getSize());
		bullets.update(clockTime);

		intTime += clockTime.asMicroseconds();
		if (clockTime.asMicroseconds() > 0 && intTime > (int)1e5) {
			text.setText(std::to_string((int)1e6 / clockTime.asMicroseconds()));
			intTime = 0;
		}
		

        window.clear(sf::Color::Black);
		player.draw(window);
		bullets.draw(window);
		enemies.draw(window);
		text.draw(window);
        window.display();
    }
    return 0;
}