#include <SFML/Graphics.hpp>
#include "States/StateController.h"
#include "States/GameState.h"
#ifdef _DEBUG
#include "vld.h"
#endif // _DEBUG


int main() {
	sf::RenderWindow window(sf::VideoMode(512, 480), "SFML works!");
	sf::View view(sf::FloatRect(0, 0, 256, 240));
	window.setView(view);
	sf::Clock clock;
	sf::Time elapsed;
	state::GameState initState(&window, &elapsed);
	state::StateController gameState(&window, &elapsed, &initState);

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

		window.clear();
		gameState.Update();
		if (gameState.HasEnded()) {
			window.close();
		}
		window.display();
	}

	return 0;
}