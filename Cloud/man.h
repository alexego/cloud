#ifndef MAN_H
#define MAN_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "manstrategy.h"

class Man : public sf::Transformable {
public:
	//� ����������� ���������� �������� ������, ��� ������� � ��������� �������
	Man(sf::Texture& text, sf::Vector2u size, sf::Vector2f pos);

	sf::Sprite getDrawable();
	sf::Vector2f getPosition();
	void setPosition(float x, float y);

	//������ � ����� ������� ������������� �������
	float getRight();
	float getLeft();
	//[���� ��� ������ ��� ������ �����������]
	//�������� ��
	int getHP();
	//�������� �����������
	int GetDestination();
	//�������� ��
	void hpIterator(float elapsed);
	void move(float offsetX, float offsetY); //����� ��� ������������� �������� ����������
	//�������� �� ������ �������
	bool IsDead();
	int Redirect(); //����������� �������� ����������� �������� ������
	int Destination; //������� ����������� �������� (�����, �����, ������)
	void Animate(float elapsed); //�������� ������ ������

private:
	sf::Sprite man; //��� ������������ � game.cpp �������� ������ ������� � ���������
	float CurrFrame; //������� ���� �� ���������� ���������
	sf::Vector2u manSize; //������� �������
	float hp;
	float animateTime;
	ManStrategy* strategy;

};

#endif // MAN_H