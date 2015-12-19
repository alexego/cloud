#ifndef GAME_H
#define GAME_H

#include <vector>
#include "cloud.h"
#include "ground.h"
#include "tree.h"
#include "man.h"
#include "menu.h"
#include "rain.h"
#include <iostream>


//Основной игровой класс
class Game : public sf::Drawable, public sf::Transformable {
public:
	//В конструктор передается текущий view и размеры экрана
	Game(sf::View gameView, sf::Vector2u screenSize);

	//Управдение движением и атакой
	void rightTrue();
	void leftTrue();
	void spaceTrue();
	void rightFalse();
	void leftFalse();
	void spaceFalse();
	void escChange();
	sf::View getView();

	//Update - движение и изменение параметров при необходимых условиях
	void update(sf::Time elapsed);
private:
	//Вектор облаков: [0] - основное облако
	//[только оно и есть, оно хранится в векторе для тренировки обработки нескольких объектов в векторе]
	std::vector<Cloud> clouds;
	//Текстура облака
	sf::Texture cloudText;
	//Скорость движение облака
	int speed;
	//Камера
	sf::View view;
	//Задний фон [не используется]
	sf::Sprite bg;
	//Вода задана прямоугольником за землей на уровне земли
	//Такие образом, когда земля опускается ниже установленного уровня, появляется вода
	sf::Sprite water;
	//Земля
	Ground ground;
	//Текстура земли
	sf::Texture groundText;
	sf::Font font;
	sf::Text text;

	std::vector<Tree> trees;
	sf::Texture treeText;

	Rain rain;
	


	//вектор роботов, картинка для анимации
	std::vector<Man> humans;
	sf::Image manImage;
	sf::Texture manText;
	int man_speed;

	//Menu pause;


	//Отвечающие за ввод логические переменные
	bool left;
	bool right;
	bool space;
	bool esc;

	//Перегруженная функция класса sf::Drawable
	//Либо отрисовывает каждый объект, если у него перегружен этот же метод
	//Либо вызывыет getDrawable() для объекта и отрисовывает получаемый объект
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // GAME_H
