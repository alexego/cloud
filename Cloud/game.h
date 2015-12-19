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
	void escChange();
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
	//�������� �����
	sf::Texture groundText;
	sf::Font font;
	sf::Text text;

	std::vector<Tree> trees;
	sf::Texture treeText;

	Rain rain;
	


	//������ �������, �������� ��� ��������
	std::vector<Man> humans;
	sf::Image manImage;
	sf::Texture manText;
	int man_speed;

	//Menu pause;


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
