#ifndef MAN_H
#define MAN_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "manstrategy.h"

class Man : public sf::Transformable {
public:
	//В конструктор передается текстура робота, его размеры и начальная позиция
	Man(sf::Texture& text, sf::Vector2u size, sf::Vector2f pos);

	sf::Sprite getDrawable();
	sf::Vector2f getPosition();
	void setPosition(float x, float y);

	//Правая и левая границы отображаемого спрайта
	float getRight();
	float getLeft();
	//[Если для дерева это вообще понадобится]
	//Получить хп
	int getHP();
	//получить направление
	int GetDestination();
	//Изменить хп
	void hpIterator(float elapsed);
	void move(float offsetX, float offsetY); //метод для осуществлении движения человечков
	//проверка на смерть объекта
	bool IsDead();
	int Redirect(); //произвольно изменяет направление движение робота
	int Destination; //текущее направление движения (влево, стоит, вправо)
	void Animate(float elapsed); //выбирает нужный спрайт

private:
	sf::Sprite man; //для анимирования в game.cpp пришлось спрайт вынести в публичные
	float CurrFrame; //текущий кард из спрайтовой отрисовки
	sf::Vector2u manSize; //размеры спрайта
	float hp;
	float animateTime;
	ManStrategy* strategy;

};

#endif // MAN_H