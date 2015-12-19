#include "menu.h"


Menu::Menu(sf::Sprite background, sf::Text mainLabel, std::vector<sf::Sprite> buttonSpritesArr, std::vector<sf::Text> buttonLabelsArr) : 
			bg(background),
			label(mainLabel),
			buttons(buttonSpritesArr),
			buttonLabels(buttonLabelsArr),
			display(false) {}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (display) {
		target.draw(bg, states);
		target.draw(label, states);
		for (std::vector<sf::Sprite>::const_iterator i = buttons.begin(); i < buttons.end(); ++i) {
			target.draw(*i, states);
		}
		for (std::vector<sf::Text>::const_iterator i = buttonLabels.begin(); i < buttonLabels.end(); ++i) {
			target.draw(*i, states);
		}
	}
}

void Menu::setDisplay(bool Display) {
	display = Display;
}