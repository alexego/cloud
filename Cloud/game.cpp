#include "game.h"
#include <string.h>

//В конструкторе задается:
//    view - через view основного окна
//    ground - через количество вершин, размеры экрана и уровня земли
//             количество вершин count должно быть (count - 4) % 200 == 0
//             так как 4 опорные вершины используются для задания основной области
//             а остальные count используются для задания сплайнов-водоемов
//             число 200/2 - шаг интерполяции, зажается в конструкторе Ground
//             [стоит передавать его как парамер, но потом]
//    clouds - через положение центра, текстуру и размеров текстуры
//    water - чере текстуру и координаты/размер
//[следует вообще все используемые константы и выражения типа "screenSize.y - screenSize.y / 3" передавать как параметр]
//    trees - 
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
	treeText.loadFromFile("tree.png");
	int treePos = 0;	
	for (int i = 0; i < 5;) {
		treePos += rand() % 200 + 100;
		if (ground.isGround(sf::Vector2f(treePos, screenSize.y - screenSize.y / 3))) {
			++i;
			Tree tree(treeText, treeText.getSize(), sf::Vector2f(treePos, screenSize.y - screenSize.y / 3));
			trees.push_back(tree);
		}
		if (treePos >= ground.getRight()) treePos = 0;
	}

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
	for (int i = 0; i < trees.size(); ++i) {
		target.draw(Tree(trees[i]).getDrawable(), states);
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
					//Раньше это делалось так:
					//Cloud& cl = clouds[i];
					//cl.move(speed * elapsed.asSeconds(), 0);
					//clouds[i] = cl;
					//Лучше оставить, вдруг в g++ не подейт этот вариант
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
