#include "ColorExtension.h"

namespace color {

sf::Color Transparent(sf::Color color) {
	color.a = 0;
	return color;
}
sf::Color Opaque(sf::Color color) {
	color.a = 255;
	return color;
}

sf::Color ChooseColor(unsigned int index) {
	sf::Color newColor;
	switch (index) {
	case 0:
		newColor = sf::Color::Blue;
		break;
	case 1:
		newColor = sf::Color::Red;
		break;
	case 2:
		newColor = sf::Color::Yellow;
		break;
	case 3:
		newColor = sf::Color::Green;
		break;
	default:
		newColor = sf::Color::Blue;
		break;
	}
	return newColor;
}

}