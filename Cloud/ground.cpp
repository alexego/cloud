#include "ground.h"
#include "spline.h"
#include <vector>

Ground::Ground(int count, sf::Vector2u screen, int groundHight) : ground(sf::TrianglesStrip, count) {
	//Ширина игрового поля
	double xWidth = 0;
	//Изменение ширины игрового поля
	double dXWidth = 0;
	sf::Color color(168, 94, 47);
	//Массивы контрольных точек для постороения сплайна
	std::vector<double> xArr(10), yArr(10);
	tk::spline spl;

	// 1: задаются две первые первые точки на нижнем уровне и на уровне земли (groundHight)
	// 2: каждые 200 (частота интерполяции 200 / 2) точек задаются 10 контрольных точек, пример:
	//    ___________              ______________
	//               \__        __/
	//                  \    __/  
	//                   \__/
	//
	//    _______________________________________
	//
	// 3: кривая из 10 контрольных точек интерполируется кубическим сплайном на 100 точек
	// 4: добавляются две последние точки
	// 5: каждые 200 точек задается область земли
	// [можно сделать рандомное кол-во точек, но как-то лень]

	ground[0].position = sf::Vector2f(0, screen.y);
	ground[1].position = sf::Vector2f(0, groundHight);
	//ground[0].color = color;
	//ground[1].color = color;
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

		ground[k].texCoords = sf::Vector2f(xPoint, 511);
		ground[k + 1].texCoords = sf::Vector2f(xPoint, 511 * (yPoint - groundHight) / (screen.y - groundHight));

		//ground[k].color = color;
		//ground[k + 1].color = color;

		if ((k - 2) % 200 == 0) {
			checkGround.push_back(CheckGround(ground[k - 1].position.x, ground[k].position.x));
		}
	}
	xWidth += std::rand() % 400 + 500 + dXWidth;
	ground[count - 2].position = sf::Vector2f(xWidth, screen.y);
	ground[count - 1].position = sf::Vector2f(xWidth, groundHight);
	//ground[count - 2].color = color;
	//ground[count - 1].color = color;

	ground[0].texCoords = sf::Vector2f(0, 511);
	ground[1].texCoords = sf::Vector2f(0, 0);
	ground[count - 2].texCoords = sf::Vector2f(xWidth, 511);
	ground[count - 1].texCoords = sf::Vector2f(xWidth, 0);

	left = 0;
	right = xWidth;

	checkGround.push_back(CheckGround(ground[count - 3].position.x, ground[count - 2].position.x));
}

sf::VertexArray Ground::getDrawable() {
	return this->ground;
}

int Ground::getLeft() {
	return this->left + 5;
}

int Ground::getRight() {
	return this->right - 5;
}

bool Ground::isGround(sf::Vector2f pos) {
	for (int i = 0; i < checkGround.size(); ++i) {
		if (pos.x >= checkGround[i].begin && pos.x <= checkGround[i].end)
			return true;
	}
	return false;
}