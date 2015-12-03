#include "ground.h"
#include "spline.h"
#include <vector>

Ground::Ground(int count, sf::Vector2u size, const int waterSize) : ground(sf::TrianglesStrip, count) {
	double xWidth = 0;
	double dXWidth = 0;
	sf::Color color(102, 60, 30);
	std::vector<double> xArr(10), yArr(10);
	tk::spline spl;
	int textRepeat = 0;
	ground[0].position = sf::Vector2f(0, size.y);
	ground[1].position = sf::Vector2f(0, size.y - 250);
	//ground[0].texCoords = sf::Vector2f(0, 1024);
	//ground[1].texCoords = sf::Vector2f(0, 1024 * (size.y - 250) / size.y);
	ground[0].color = color;
	ground[1].color = color;
	for (int k = 2; k < count - 2; k += 2) {
		if ((k-2) % 200 == 0) {
			xWidth += std::rand() % 400 + 500 + dXWidth;
			dXWidth = 0;
			xArr[0] = xWidth; yArr[0] = size.y - 250;
			dXWidth += std::rand() % 50 + 50;
			xArr[1] = xWidth + dXWidth; yArr[1] = size.y + std::rand() % 80 - 210;
			dXWidth += std::rand() % 50 + 50;
			xArr[2] = xWidth + dXWidth; yArr[2] = size.y + std::rand() % 80 - 210;
			dXWidth += std::rand() % 50 + 50;
			xArr[3] = xWidth + dXWidth; yArr[3] = size.y + std::rand() % 80 - 210;
			dXWidth += std::rand() % 50 + 50;
			xArr[4] = xWidth + dXWidth; yArr[4] = size.y + std::rand() % 80 - 210;
			dXWidth += std::rand() % 50 + 50;
			xArr[5] = xWidth + dXWidth; yArr[5] = size.y + std::rand() % 80 - 210;
			dXWidth += std::rand() % 50 + 50;
			xArr[6] = xWidth + dXWidth; yArr[6] = size.y + std::rand() % 80 - 210;
			dXWidth += std::rand() % 50 + 50;
			xArr[7] = xWidth + dXWidth; yArr[7] = size.y + std::rand() % 80 - 210;
			dXWidth += std::rand() % 50 + 50;
			xArr[8] = xWidth + dXWidth; yArr[8] = size.y + std::rand() % 80 - 210;
			dXWidth += std::rand() % 50 + 50;
			xArr[9] = xWidth + dXWidth; yArr[9] = size.y - 250;			
			spl.set_points(xArr, yArr);
		}
		double xPoint = double((k - 2) % 200) / 198 * dXWidth + xWidth;
		double yPoint = spl(xPoint);
		ground[k].position = sf::Vector2f(xPoint, size.y);
		ground[k + 1].position = sf::Vector2f(xPoint, yPoint);

		//ground[k].texCoords = sf::Vector2f(xPoint, 1024);
		//ground[k + 1].texCoords = sf::Vector2f(xPoint, 1024 * yPoint / size.y);

		ground[k].color = color;
		ground[k + 1].color = color;

	}
	xWidth += std::rand() % 400 + 500 + dXWidth;
	ground[count - 2].position = sf::Vector2f(xWidth, size.y);
	ground[count - 1].position = sf::Vector2f(xWidth, size.y - 250);
	//ground[count - 2].texCoords = sf::Vector2f(xWidth, 1024);
	//ground[count - 1].texCoords = sf::Vector2f(xWidth, 1024 * (size.y - 250) / size.y);

	ground[count - 2].color = color;
	ground[count - 1].color = color;

	left = 0;
	right = xWidth;
	for (int i = 0; i < count; ++i) {
		std::cout << ground[i].position.x << ' ' << ground[i].position.y << std::endl;
	}
}

sf::VertexArray Ground::getDrawable() {
	return this->ground;
}

int Ground::getLeft() {
	return this->left;
}

int Ground::getRight() {
	return this->right;
}
