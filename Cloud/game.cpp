#include "game.h"

Game::Game(sf::View VIEW, sf::Vector2u SIZE) : view(VIEW), ground(2004, SIZE, 5) {
	Cloud newCloud;
	clouds.push_back(newCloud);
	std::cout << clouds.size() << std::endl;
	right = false;
	left = false;
	space = false;
	speed = 1000;
	groundText.create(1024, 1024);
	groundText.loadFromFile("ground.jpg");
	groundText.setRepeated(true);

	sf::Texture waterText;
	waterText.create(ground.getRight(), SIZE.y - 250);
	water.setTexture(waterText);
	water.setColor(sf::Color(119, 221, 231));
	water.setPosition(sf::Vector2f(0, SIZE.y - 250));

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
sf::View Game::getViev() {
	return view;
}
void Game::update(sf::Time elapsed) {
	if (right) {
		if (view.getCenter().x + view.getSize().x/2 < ground.getRight() - 5) {
			for (int i = 0; i < clouds.size(); ++i) {
				Cloud& cl = clouds[i];
				cl.move(speed * elapsed.asSeconds(), 0);
				clouds[i] = cl;
			}
			view.move(speed * elapsed.asSeconds(), 0);
		}
	}
	if (left) {
		if (view.getCenter().x - view.getSize().x / 2 > ground.getLeft() + 5) {
			for (int i = 0; i < clouds.size(); ++i) {
				Cloud& cl = clouds[i];
				cl.move(-speed * elapsed.asSeconds(), 0);
				clouds[i] = cl;
			}
			view.move(-speed * elapsed.asSeconds(), 0);
		}
	}
}
