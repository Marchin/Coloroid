#include "Controllers\GameController.h"

namespace controller {
	GameController::GameController() {
		using namespace input;
		keys.push_back(Input(sf::Keyboard::Space));
		keys.push_back(Input(sf::Keyboard::Space));
		keys.push_back(Input(sf::Keyboard::Left));
		keys.push_back(Input(sf::Keyboard::Right));
		keys.push_back(Input(sf::Keyboard::A));
		keys.push_back(Input(sf::Keyboard::S));
		keys.push_back(Input(sf::Keyboard::D));
		keys.push_back(Input(sf::Keyboard::F));
	}

	void GameController::UpdateKeys() {
		using namespace input;
		for (int i = 0; i < keys.size; i++) {
			keys[i].Update();
		}
	}

	bool GameController::Fire() {
		return keys[FIRE].PressDown();
	}

	bool GameController::RotateLeft() {
		return keys[ROTATE_LEFT].IsPressed();
	}

	bool GameController::RotateRight() {
		return keys[ROTATE_RIGHT].IsPressed();
	}

	bool GameController::ColorizeBlue() {
		return keys[COLORIZE_BLUE].PressDown();
	}

	bool GameController::ColorizeRed() {
		return keys[COLORIZE_RED].PressDown();
	}

	bool GameController::ColorizeGreen() {
		return keys[COLORIZE_GREEN].PressDown();
	}

	bool GameController::ColorizeYellow() {
		return keys[COLORIZE_YELLOW].PressDown();
	}
}