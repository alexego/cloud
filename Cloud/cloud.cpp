#include "cloud.h"

Cloud::Cloud(sf::Vector2f center, sf::Texture& text, sf::Vector2u size) : cloud(text), hp(100.0f) {
	cloud.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
	cloud.setScale(0.3, 0.3);
	cloud.setPosition(center);
	cloudSize = size;
	std::cout << cloud.getPosition().x << ' ' << cloud.getPosition().y << std::endl;
}

sf::Sprite Cloud::getDrawable() {
	return this->cloud;
}

void Cloud::move(float offsetX, float offsetY) {
	cloud.move(offsetX, offsetY);
}

sf::Vector2f Cloud::getPosition() {
	return cloud.getPosition();
}

float Cloud::getRight() {
	return cloud.getPosition().x + cloudSize.x * cloud.getScale().x / 2;
}

float Cloud::getLeft() {
	return cloud.getPosition().x - cloudSize.x * cloud.getScale().x / 2;
}

int Cloud::getHP() {
	return hp;
}

void Cloud::hpIterator(float elapsed) {
	hp += elapsed;
}