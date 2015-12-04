#include "ground.h"
#include "spline.h"
#include <vector>

Ground::Ground(int count, sf::Vector2u screen, int groundHight) : ground(sf::TrianglesStrip, count) {
	double xWidth = 0;
	double dXWidth = 0;
	sf::Color color(168, 94, 47);
	std::vector<double> xArr(10), yArr(10);
	tk::spline spl;
	int textRepeat = 0;
	ground[0].position = sf::Vector2f(0, screen.y);
	ground[1].position = sf::Vector2f(0, groundHight);
	ground[0].color = color;
	ground[1].color = color;
	for (int k = 2; k < count - 2; k += 2) {
		if ((k-2) % 200 == 0) {
			xWidth += std::rand() % 400 + 500 + dXWidth;
			dXWidth = 0;
			xArr[0] = xWidth; yArr[0] = groundHight;
			dXWidth += std::rand() % 50 + 50;
			xArr[1] = xWidth + dXWidth; yArr[1] = groundHight + 50 + rand() % (screen.y - 100 - groundHight);
			dXWidth += std::rand() % 50 + 50;
			xArr[2] = xWidth + dXWidth; yArr[2] = groundHight + 50 + rand() % (screen.y - 100 - groundHight);
			dXWidth += std::rand() % 50 + 50;
			xArr[3] = xWidth + dXWidth; yArr[3] = groundHight + 50 + rand() % (screen.y - 100 - groundHight);
			dXWidth += std::rand() % 50 + 50;
			xArr[4] = xWidth + dXWidth; yArr[4] = groundHight + 50 + rand() % (screen.y - 100 - groundHight);
			dXWidth += std::rand() % 50 + 50;
			xArr[5] = xWidth + dXWidth; yArr[5] = groundHight + 50 + rand() % (screen.y - 100 - groundHight);
			dXWidth += std::rand() % 50 + 50;
			xArr[6] = xWidth + dXWidth; yArr[6] = groundHight + 50 + rand() % (screen.y - 100 - groundHight);
			dXWidth += std::rand() % 50 + 50;
			xArr[7] = xWidth + dXWidth; yArr[7] = groundHight + 50 + rand() % (screen.y - 100 - groundHight);
			dXWidth += std::rand() % 50 + 50;
			xArr[8] = xWidth + dXWidth; yArr[8] = groundHight + 50 + rand() % (screen.y - 100 - groundHight);
			dXWidth += std::rand() % 50 + 50;
			xArr[9] = xWidth + dXWidth; yArr[9] = groundHight;
			spl.set_points(xArr, yArr);
		}
		double xPoint = double((k - 2) % 200) / 198 * dXWidth + xWidth;
		double yPoint = spl(xPoint);
		ground[k].position = sf::Vector2f(xPoint, screen.y);
		ground[k + 1].position = sf::Vector2f(xPoint, yPoint);

		//ground[k].texCoords = sf::Vector2f(xPoint, 1024);
		//ground[k + 1].texCoords = sf::Vector2f(xPoint, 1024 * yPoint / screen.y);

		ground[k].color = color;
		ground[k + 1].color = color;

		if ((k - 2) % 200 == 0) {
			checkGround.push_back(CheckGround(ground[k - 1].position.x, ground[k].position.x));
		}
	}
	xWidth += std::rand() % 400 + 500 + dXWidth;
	ground[count - 2].position = sf::Vector2f(xWidth, screen.y);
	ground[count - 1].position = sf::Vector2f(xWidth, groundHight);
	ground[count - 2].color = color;
	ground[count - 1].color = color;

	//ground[0].texCoords = sf::Vector2f(0, 1024);
	//ground[1].texCoords = sf::Vector2f(0, 1024 * (screen.y - 250) / screen.y);
	//ground[count - 2].texCoords = sf::Vector2f(xWidth, 1024);
	//ground[count - 1].texCoords = sf::Vector2f(xWidth, 1024 * (screen.y - 250) / screen.y);

	left = 0;
	right = xWidth;

	checkGround.push_back(CheckGround(ground[count - 3].position.x, ground[count - 2].position.x));

	for (int i = 0; i < checkGround.size(); ++i) {
		std::cout << checkGround[i].begin << ' ' << checkGround[i].end << std::endl;
	}
	std::cout << left << ' ' << right << std::endl;
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

bool Ground::isGround(sf::Vector2f pos) {
	for (int i = 0; i < checkGround.size(); ++i) {
		if (pos.x >= checkGround[i].begin && pos.x <= checkGround[i].end)
			return true;
	}
	return false;
}