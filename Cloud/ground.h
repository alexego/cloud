#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Ground {
public:
	Ground(int count, sf::Vector2u size, int waterSize);
	sf::ConvexShape getDrawable();
private:
	sf::ConvexShape ground;
};

#endif // GROUND_H
