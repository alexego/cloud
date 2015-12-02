#include "cloud.h"

Cloud::Cloud() {
		sf::Texture texture;
		texture.create(20, 20);
		cloud.setTexture(texture);
		cloud.setColor(sf::Color(0, 255, 0));
		cloud.setPosition(sf::Vector2f(10, 50));
	}
