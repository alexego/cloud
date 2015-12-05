#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Ground {
public:
	//Конструктор принимает количество вершин, размеры экрана и уровень земли
	Ground(int count, sf::Vector2u screen, int groundHight);
	sf::VertexArray getDrawable();
	//Определение левой и правой границы игровой области
	int getLeft();
	int getRight();
	//Проверяется, раходится ли точка над землей или над водой
	bool isGround(sf::Vector2f pos);
private:
	//Структура описывает начало и конец поверхности земли между водой
	//Необходимо для isGround(...)
	struct CheckGround {
		float begin;
		float end;

		CheckGround(float a, float b) : begin(a), end(b) {}
	};
	//Массив вершин типа sf::TrianglesStrip для отрисовки земли
	sf::VertexArray ground;
	//Правая и левая границы игровой области
	int left;
	int right;
	
	std::vector<CheckGround> checkGround;
};

#endif // GROUND_H
