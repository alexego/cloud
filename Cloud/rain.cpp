#include "rain.h"


Rain::Rain(float maxDelay, int velocity, int ground) : drops(sf::Quads), speed(velocity), delay(maxDelay), high(ground), color(63, 143, 255), dropCount(0) {
	sf::Color color(63, 143, 255);
}

void Rain::setEmitter(sf::Vector2f point) {
	emitter = point;
}

void Rain::setArea(float width) {
	area = width - 20;
}

void Rain::emit(sf::Time elapsed) {
	emitTime += elapsed;

	if (emitTime.asSeconds() >= delay * dropCount) {
		sf::RectangleShape newDrop(sf::Vector2f(3, 10));
		newDrop.move(sf::Vector2f(emitter.x - std::rand() % (area / 2) - (area / 2 - 1)*((dropCount) % 2) - 10, emitter.y - 10));
		newDrop.setFillColor(color);
		drops.insert(drops.end(), newDrop);
		++dropCount;
	}

	for (std::vector<sf::RectangleShape>::iterator i = drops.begin(); i < drops.end();) {
		i->move(0, speed*elapsed.asSeconds());
		if (i->getPosition().y >= high) {
			i = drops.erase(i);
		} else {
			++i;
		}
	}
}

void Rain::noemit(sf::Time elapsed) {
	emitTime = sf::Time();
	dropCount = 0;
	for (std::vector<sf::RectangleShape>::iterator i = drops.begin(); i < drops.end();) {
		i->move(0, speed*elapsed.asSeconds());
		if (i->getPosition().y >= high) {
			i = drops.erase(i);
		} else {
			++i;
		}
	}
}

void Rain::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (std::vector<sf::RectangleShape>::const_iterator i = drops.begin(); i < drops.end(); ++i) {
		target.draw(*i, states);
	}
}