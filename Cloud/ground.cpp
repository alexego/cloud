#include "ground.h"
#include "spline.h"
#include <vector>

Ground::Ground(int count, sf::Vector2u size, const int waterSize) {
	double xWidth = 0;
	double dXWidth = 0;
	std::vector<double> xArr(5), yArr(5);
	tk::spline spl;
	ground.setPointCount(count);
	for (int k = 0; k < count - 4; ++k) {
		if (k % 200 == 0) {
			xWidth += std::rand() % 400 + 500 + dXWidth;
			xArr[0] = xWidth; yArr[0] = -250;
			dXWidth += std::rand() % 50 + 50;
			xArr[1] = xWidth + dXWidth; yArr[1] = std::rand() % 80 - 210;
			dXWidth += std::rand() % 50 + 50;
			xArr[2] = xWidth + dXWidth; yArr[2] = std::rand() % 80 - 210;
			dXWidth += std::rand() % 50 + 50;
			xArr[3] = xWidth + dXWidth; yArr[3] = std::rand() % 80 - 210;
			dXWidth += std::rand() % 50 + 50;
			xArr[4] = xWidth + dXWidth; yArr[4] = -250;
			std::cout << k << std::endl;

			spl.set_points(xArr, yArr);
		}
		float xPoint = float(k % 200) / 199 * dXWidth + xWidth;
		ground.setPoint(k, sf::Vector2f(xPoint, spl(xPoint)));
	}
	xWidth += std::rand() % 400 + 500;
	ground.setPoint(count - 4, sf::Vector2f(xWidth, -250));
	ground.setPoint(count - 3, sf::Vector2f(xWidth, 100000));
	ground.setPoint(count - 2, sf::Vector2f(0, 100000));
	ground.setPoint(count - 1, sf::Vector2f(0, -250));
	ground.setPosition(0, size.y);
	ground.setFillColor(sf::Color(100, 20, 70));
	for (int i = 0; i < count; ++i) {
		std::cout << ground.getPoint(i).x << ' ' << ground.getPoint(i).y << std::endl;
	}
	std::cout << ground.getPointCount();
}

sf::ConvexShape Ground::getDrawable() {
	return this->ground;
}
