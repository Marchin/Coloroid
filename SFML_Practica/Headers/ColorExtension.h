#ifndef COLOR_EXTENSION_H
#define COLOR_EXTENSION_H

#include <SFML/Graphics/Color.hpp>

namespace color {

sf::Color Transparent(sf::Color color);
sf::Color Opaque(sf::Color color);

}
#endif // !COLOR_EXTENSION_H
