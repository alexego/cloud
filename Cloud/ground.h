#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Ground {
public:
	Ground(int count, sf::Vector2u size, int waterSize);
	sf::VertexArray getDrawable();
	int getLeft();
	int getRight();
private:
	sf::VertexArray ground;
	int left;
	int right;
};

#endif // GROUND_H
