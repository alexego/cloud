#include <SFML/Graphics.hpp>

#include "cloud.h"
#include "game.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1024, 576), "Cloud", sf::Style::Default, settings);

	Game game(window.getView(), window.getSize());
	// create a clock to track the elapsed time
	sf::Clock clock;

	// run the main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
				switch (event.key.code) {
				case sf::Keyboard::D:
					game.rightTrue();
					break;
				case sf::Keyboard::A:
					game.leftTrue();
					break;
			}
			if (event.type == sf::Event::KeyReleased)
				switch (event.key.code) {
				case sf::Keyboard::D:
					game.rightFalse();
					break;
				case sf::Keyboard::A:
					game.leftFalse();
					break;
			}
		}
		//sf::Texture textu;
		//textu.loadFromFile("cloud.png");
		//Cloud cld(sf::Vector2f(500, 200), textu);
		// update
		sf::Time elapsed = clock.restart();
		game.update(elapsed);

		// draw
		window.clear(sf::Color(127, 199, 255));
		window.setView(game.getViev());
		window.draw(game);
		//window.draw(cld);
		window.display();
	}

	return 0;
}
