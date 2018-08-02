#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Controllers\GameController.h"
#ifdef _DEBUG
#include "vld.h"
#endif // _DEBUG


int main() {
	sf::RenderWindow window(sf::VideoMode(512, 480), "SFML works!");
	sf::View view(sf::FloatRect(0, 0, 256, 240));
	window.setView(view);
	sf::Vector2f screenCenter(view.getSize().x / 2.f, view.getSize().y / 2.f);
	player::Player player(screenCenter, &view);
	sf::Clock clock;
	sf::Time elapsed;
	std::array<sf::Sprite, 0> spriteVec;
	input::GameController gameController;

	while (window.isOpen()) {
		sf::Event event;
		elapsed = clock.restart();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}

		gameController.UpdateKeys();
		if (gameController.RotateLeft()) {
			player.Rotate(-90.f, elapsed.asSeconds());
		}
		if (gameController.RotateRight()) {
			player.Rotate(90.f, elapsed.asSeconds());
		}
		if (gameController.Fire()) {
			player.Fire();
		}
		if (gameController.ColorizeBlue()) {
			player.SetColor(sf::Color::Blue);
		}
		if (gameController.ColorizeRed()) {
			player.SetColor(sf::Color::Red);
		}
		if (gameController.ColorizeGreen()) {
			player.SetColor(sf::Color::Green);
		}
		if (gameController.ColorizeYellow()) {
			player.SetColor(sf::Color::Yellow);
		}

		player.UpdateShots(spriteVec, elapsed.asSeconds());

		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}