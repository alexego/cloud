#ifndef GAME_H
#define GAME_H

#include <vector>
#include "cloud.h"
#include "ground.h"
#include <iostream>
#include <sstream>

//�������� ������� �����
class Game : public sf::Drawable, public sf::Transformable {
public:
	//� ����������� ���������� ������� view � ������� ������
	Game(sf::View gameView, sf::Vector2u screenSize);

	//���������� ��������� � ������
	void rightTrue();
	void leftTrue();
	void spaceTrue();
	void rightFalse();
	void leftFalse();
	void spaceFalse();
	sf::View getView();

	//Update - �������� � ��������� ���������� ��� ����������� ��������
	void update(sf::Time elapsed);
private:
	//������ �������: [0] - �������� ������
	//[������ ��� � ����, ��� �������� � ������� ��� ���������� ��������� ���������� �������� � �������]
	std::vector<Cloud> clouds;
	//�������� ������
	sf::Texture cloudText;
	//�������� �������� ������
	int speed;
	//������
	sf::View view;
	//������ ��� [�� ������������]
	sf::Sprite bg;
	//���� ������ ��������������� �� ������ �� ������ �����
	//����� �������, ����� ����� ���������� ���� �������������� ������, ���������� ����
	sf::Sprite water;
	//�����
	Ground ground;
	//�������� ����� [�� ������������, ��� ���������������]
	sf::Texture groundText;
	sf::Font font;
	sf::Text text;

	std::ostringstream plrStr;
	


	//���������� �� ���� ���������� ����������
	bool left;
	bool right;
	bool space;
	bool esc;

	//������������� ������� ������ sf::Drawable
	//���� ������������ ������ ������, ���� � ���� ���������� ���� �� �����
	//���� �������� getDrawable() ��� ������� � ������������ ���������� ������
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // GAME_H
