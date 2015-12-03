#ifndef GAME_H
#define GAME_H

#include <vector>
#include "cloud.h"
#include "ground.h"
#include <iostream>

class Game : public sf::Drawable, public sf::Transformable {
public:
	Game(sf::View VIEW, sf::Vector2u SIZE);

	void rightTrue();
	void leftTrue();
	void spaceTrue();
	void rightFalse();
	void leftFalse();
	void spaceFalse();
	sf::View getViev();
	void update(sf::Time elapsed);
private:
	std::vector<Cloud> clouds;
	sf::View view;
	sf::Sprite bg;
	sf::Sprite water;
	Ground ground;
	sf::Texture groundText;
	bool left;
	bool right;
	bool space;
	int speed;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // GAME_H
