#ifndef CLOUD_H
#define CLOUD_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Cloud : public sf::Transformable {
public:
	Cloud();

	sf::Sprite getDrawable() {
		return this->cloud;
	}

	void move(float offsetX, float offsetY) {
		cloud.move(offsetX, offsetY);
	}
private:
	sf::Sprite cloud;

};

#endif // CLOUD_H
