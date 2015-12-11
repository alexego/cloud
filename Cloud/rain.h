#ifndef RAIN_H
#define RAIN_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Rain : public sf::Drawable, public sf::Transformable {
public:
	Rain(float maxDelay, int velocity, int high);
	void setEmitter(sf::Vector2f point);
	void setArea(float width);
	void emit(sf::Time elapsed);
	void noemit(sf::Time elapsed);
private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::vector<sf::RectangleShape> drops;
	sf::Vector2f emitter;
	int area;
	int speed;
	float delay;
	int high;
	sf::Color color;

	sf::Time emitTime;
	int dropCount;
};

#endif //RAIN_H