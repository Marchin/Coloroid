#include <SFML/Graphics.hpp>
#include "Player.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(512, 480), "SFML works!");
	sf::View view(sf::FloatRect(0, 0, 256, 240));
	window.setView(view);
	sf::Vector2f screenCenter(view.getSize().x / 2.f, view.getSize().y / 2.f);
	player::Player player(screenCenter, &view);
	sf::Clock clock;
	sf::Time elapsed;
	std::array<sf::Sprite, 0> spriteVec;
	/*sf::Sprite sprite;
	spriteVec.push_back(sprite);*/

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			player.Fire();
		}
		player.UpdateShotsMovement(spriteVec, elapsed.asSeconds());

		window.clear();
		window.draw(player.GetPlayer());
		window.display();
	}

	return 0;
}