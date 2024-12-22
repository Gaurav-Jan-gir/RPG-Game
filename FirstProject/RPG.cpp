#pragma once
#include "Settings.h"
#include "Enemy.h"
#include "Bullets.h"

int main()
{
    sf::ContextSettings setting;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Default, setting);
	Settings settings;
	settings.setup(window, setting);

	Player player;
	Enemy enemy;
	Bullets bullets;	

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
		bool caseI = sf::Keyboard::isKeyPressed(sf::Keyboard::I);
		bool caseJ = sf::Keyboard::isKeyPressed(sf::Keyboard::J);
		bool caseK = sf::Keyboard::isKeyPressed(sf::Keyboard::K);
		bool caseL = sf::Keyboard::isKeyPressed(sf::Keyboard::L);
		if (caseI || caseJ || caseK || caseL)
			bullets.load(player);
		player.update();
		enemy.update();
		bullets.update();

        window.clear(sf::Color::Black);
		player.draw(window);
		bullets.draw(window);
		enemy.draw(window);
        window.display();
    }
    return 0;
}