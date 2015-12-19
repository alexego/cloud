#ifndef MENU_H
#define MENU_H
#include <SFML\Graphics.hpp>

class Menu : sf::Drawable, sf::Transformable {
public:
	Menu(sf::Sprite background, sf::Text mainLabel, std::vector<sf::Sprite> buttonSpritesArr, std::vector<sf::Text> buttonLabelsArr);

	void setDisplay(bool Display);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Sprite bg;
	sf::Text label;
	std::vector<sf::Sprite> buttons;
	std::vector<sf::Text> buttonLabels;
	bool display;
};

#endif