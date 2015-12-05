#ifndef TREE_H
#define TREE_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Tree : public sf::Transformable {
public:
	//� ����������� ���������� �������� ������, �� ������� � ������� ������
	Tree(sf::Texture& text, sf::Vector2u size, sf::Vector2f pos);

	sf::Sprite getDrawable();
	sf::Vector2f getPosition();
	void setPosition(float x, float y);

	//������ � ����� ������� ������������� �������
	float getRight();
	float getLeft();
	//[���� ��� ������ ��� ������ �����������]
	//�������� ��
	int getHP();
	//�������� ��
	void hpIterator(float elapsed);
private:
	sf::Sprite tree;
	sf::Vector2u treeSize;
	float hp;
};

#endif // TREE_H