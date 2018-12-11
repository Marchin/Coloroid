#include <SFML/Graphics.hpp>
#include "States/StateController.h"
#include "States/StartState.h"
#include <ctime>
#ifdef _DEBUG
#include "vld.h"
#endif // _DEBUG


int main() {
	sf::RenderWindow window(sf::VideoMode(512, 480), "Coloroid");
	sf::View view(sf::FloatRect(0, 0, 256, 240));
	window.setView(view);
	sf::Clock clock;
	sf::Time elapsed;
	state::StartState initState(&window, &elapsed);
	state::StateController stateController(&window, &elapsed, &initState);

	srand(time(0));

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
		stateController.Update();
		if (stateController.HasEnded()) {
			window.close();
		}
		window.display();
	}

	return 0;
}