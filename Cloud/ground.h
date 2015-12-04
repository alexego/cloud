#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Ground {
public:
	Ground(int count, sf::Vector2u screen, int groundHight);
	sf::VertexArray getDrawable();
	int getLeft();
	int getRight();
	bool isGround(sf::Vector2f pos);
private:

	struct CheckGround {
		float begin;
		float end;

		CheckGround(float a, float b) : begin(a), end(b) {}
	};

	sf::VertexArray ground;
	int left;
	int right;
	std::vector<CheckGround> checkGround;
};

#endif // GROUND_H
