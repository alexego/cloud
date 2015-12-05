#include "game.h"
#include <string.h>

//� ������������ ��������:
//    view - ����� view ��������� ����
//    ground - ����� ���������� ������, ������� ������ � ������ �����
//             ���������� ������ count ������ ���� (count - 4) % 200 == 0
//             ��� ��� 4 ������� ������� ������������ ��� ������� �������� �������
//             � ��������� count ������������ ��� ������� ��������-��������
//             ����� 200/2 - ��� ������������, �������� � ������������ Ground
//             [����� ���������� ��� ��� �������, �� �����]
//    clouds - ����� ��������� ������, �������� � �������� ��������
//    water - ���� �������� � ����������/������
//[������� ������ ��� ������������ ��������� � ��������� ���� "screenSize.y - screenSize.y / 3" ���������� ��� ��������]
Game::Game(sf::View gameView, sf::Vector2u screenSize) : view(gameView), ground(2004, screenSize, screenSize.y - screenSize.y/3),text("", font, 20) {
	cloudText.create(541, 171);
	cloudText.loadFromFile("cloud.png");
	cloudText.setSmooth(true);
	Cloud newCloud(sf::Vector2f(screenSize.x / 2, screenSize.y / 4), cloudText, cloudText.getSize());
	clouds.push_back(newCloud);

	right = false;
	left = false;
	space = false;
	speed = 1000;
	esc = false;
	//groundText.create(1024, 1024);
	//groundText.loadFromFile("ground.jpg");
	//groundText.setRepeated(true);

	text.setPosition(10, 10);
	
	font.loadFromFile("arial.ttf");
	


	sf::Texture waterText;
	waterText.create(ground.getRight(), screenSize.y - screenSize.y / 3);
	water.setTexture(waterText);
	water.setColor(sf::Color(0, 127, 255));
	water.setPosition(sf::Vector2f(0, screenSize.y - screenSize.y / 3));
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	states.texture = NULL;

	for (int i = 0; i < clouds.size(); ++i) {
		target.draw(Cloud(clouds[i]).getDrawable(), states);
	}

	target.draw(water, states);
	//states.texture = &groundText;
	target.draw(Ground(ground).getDrawable(), states);

	target.draw(text, states);
}

void Game::rightTrue() {
	this->right = true;
}
void Game::leftTrue() {
	this->left = true;
}
void Game::spaceTrue() {
	this->space = true;
}
void Game::rightFalse() {
	this->right = false;
}
void Game::leftFalse() {
	this->left = false;
}
void Game::spaceFalse() {
	this->space = false;
}

sf::View Game::getView() {
	return view;
}

void Game::update(sf::Time elapsed) {
	if (!esc) {
		if (right) {
			if (view.getCenter().x + view.getSize().x / 2 < ground.getRight() - 5 && clouds[0].getPosition().x >= view.getCenter().x - 5) {
				view.move(speed * elapsed.asSeconds(), 0);
			}
			if (clouds[0].getRight() < ground.getRight() - 6) {
				for (int i = 0; i < clouds.size(); ++i) {
					clouds[i].move(speed * elapsed.asSeconds(), 0);
					//������ ��� �������� ���:
					//Cloud& cl = clouds[i];
					//cl.move(speed * elapsed.asSeconds(), 0);
					//clouds[i] = cl;
					//����� ��������, ����� � g++ �� ������ ���� �������
				}
			}
		}
		if (left) {
			if (view.getCenter().x - view.getSize().x / 2 > ground.getLeft() + 5 && clouds[0].getPosition().x <= view.getCenter().x + 5) {
				view.move(-speed * elapsed.asSeconds(), 0);
			}
			if (clouds[0].getLeft() > ground.getLeft() + 6) {
				for (int i = 0; i < clouds.size(); ++i) {
					clouds[i].move(-speed * elapsed.asSeconds(), 0);
				}
			}
		}

		//std::cout << ground.isGround(clouds[0].getPosition());	

		if (ground.isGround(clouds[0].getPosition())) {
			clouds[0].hpIterator(-elapsed.asSeconds());
		}
		else {
			clouds[0].hpIterator(elapsed.asSeconds());
		}
	}
	text.setPosition(sf::Vector2f(view.getCenter().x - 500, 0));
	text.setString(std::to_string(clouds[0].getHP()));
	std::cout << 1.f/elapsed.asSeconds() << std::endl;
}
