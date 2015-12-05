#ifndef TREE_H
#define TREE_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Tree : public sf::Transformable {
public:
	//В конструктор передается координаты центра экрана, текстура облака и ее размеры
	Tree(sf::Texture& text, sf::Vector2u size, sf::Vector2f pos);

	sf::Sprite getDrawable();
	sf::Vector2f getPosition();
	void setPosition(float x, float y);
	//Правая и левая границы отображаемого спрайта
	float getRight();
	float getLeft();
	//Получить хп
	int getHP();
	//Изменить хп [и положение облака]
	void hpIterator(float elapsed);
private:
	sf::Sprite tree;
	sf::Vector2u treeSize;
	float hp;
};

#endif // TREE_H