#include <SFML/Graphics.hpp>
#include "Player.h"

int main() {
	player::Player player;
	sf::RenderWindow window(sf::VideoMode(256, 240), "SFML works!");
	sf::Vector2f screenCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);
	player.Move(screenCenter);
	sf::Clock clock;
	sf::Time elapsed;

	while (window.isOpen()) {
		sf::Event event;
		elapsed = clock.restart();
		player.GetPlayer().setPosition(sf::Vector2f(100.f, 100.f));
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			player.Rotate(90.f, elapsed.asSeconds());
		}

		window.clear();
		window.draw(player.GetPlayer());
		window.display();
	}

	return 0;
}