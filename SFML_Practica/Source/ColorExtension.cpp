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

}