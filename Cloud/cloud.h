#ifndef CLOUD_H
#define CLOUD_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Cloud : public sf::Transformable{
public:
	//В конструктор передается координаты центра экрана, текстура облака и ее размеры
	Cloud(sf::Vector2f center, sf::Texture& text, sf::Vector2u size);

	sf::Sprite getDrawable();

	void move(float offsetX, float offsetY);
	sf::Vector2f getPosition();
	//Правая и левая границы отображаемого спрайта
	float getRight();
	float getLeft();
	//Получить хп
	int getHP();
	//Изменить хп [и положение облака]
	void hpIterator(float elapsed);
private:
	sf::Sprite cloud;
	sf::Vector2u cloudSize;
	float hp;
};

#endif // CLOUD_H
