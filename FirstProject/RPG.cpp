#include <SFML/Graphics.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!", sf::Style::Default, settings);
	window.setVerticalSyncEnabled(true);
    sf::CircleShape shape(50.f,4);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(shape.getRadius(),shape.getRadius());
    shape.setPosition(250, 250);
    shape.setRotation(45);
    float i = 0.1f;

    while (window.isOpen())
    {
        i += 0.5f;
		shape.setRotation((int)i%360);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Red);
        window.draw(shape);
        window.display();
    }

    return 0;
}