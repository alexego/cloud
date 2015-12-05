#include "tree.h"

Tree::Tree(sf::Texture& text, sf::Vector2u size, sf::Vector2f pos) : tree(text), hp(100.0f) {
	tree.setOrigin(sf::Vector2f(size.x / 2, size.y));
	tree.setScale(0.2, 0.2);
	tree.setPosition(pos);
	treeSize = size;
	std::cout << size.x * tree.getScale().x << ' ' << tree.getPosition().y << std::endl;
}

sf::Sprite Tree::getDrawable() {
	return this->tree;
}

sf::Vector2f Tree::getPosition() {
	return tree.getPosition();
}

void Tree::setPosition(float x, float y) {
	tree.setPosition(x, y);
}

float Tree::getRight() {
	return tree.getPosition().x + treeSize.x * tree.getScale().x / 2;
}

float Tree::getLeft() {
	return tree.getPosition().x - treeSize.x * tree.getScale().x / 2;
}

int Tree::getHP() {
	return hp;
}

void Tree::hpIterator(float elapsed) {
	if (elapsed > 0) {
		hp += elapsed * 4;
		return;
	}
	hp += elapsed;
}