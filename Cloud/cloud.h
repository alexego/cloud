#ifndef CLOUD_H
#define CLOUD_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Cloud : public sf::Transformable{
public:
	Cloud(sf::Vector2f center, sf::Texture& text, sf::Vector2u size);

	sf::Sprite getDrawable();

	void move(float offsetX, float offsetY);
	sf::Vector2f getPosition();
	float getRight();
	float getLeft();
	int getHP();
	void hpIterator(float elapsed);
private:
	sf::Sprite cloud;
	sf::Vector2u cloudSize;
	float hp;
};

#endif // CLOUD_H
