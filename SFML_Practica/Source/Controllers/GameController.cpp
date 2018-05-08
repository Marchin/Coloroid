#include "Controllers\GameController.h"

namespace controller {
	GameController::GameController() {
		using namespace input;
		m_keys[FIRE] = Input(sf::Keyboard::Space);
		m_keys[ROTATE_LEFT] = Input(sf::Keyboard::Left);
		m_keys[ROTATE_RIGHT] = Input(sf::Keyboard::Right);
		m_keys[COLORIZE_BLUE] = Input(sf::Keyboard::A);
		m_keys[COLORIZE_RED] = Input(sf::Keyboard::S);
		m_keys[COLORIZE_GREEN] = Input(sf::Keyboard::D);
		m_keys[COLORIZE_YELLOW] = Input(sf::Keyboard::F);
	}

	void GameController::UpdateKeys() {
		using namespace input;
		for (int i = 0; i < m_keys.size(); i++) {
			m_keys[i].Update();
		}
	}

	bool GameController::Fire() {
		return m_keys[FIRE].PressDown();
	}

	bool GameController::RotateLeft() {
		return m_keys[ROTATE_LEFT].IsPressed();
	}

	bool GameController::RotateRight() {
		return m_keys[ROTATE_RIGHT].IsPressed();
	}

	bool GameController::ColorizeBlue() {
		return m_keys[COLORIZE_BLUE].PressDown();
	}

	bool GameController::ColorizeRed() {
		return m_keys[COLORIZE_RED].PressDown();
	}

	bool GameController::ColorizeGreen() {
		return m_keys[COLORIZE_GREEN].PressDown();
	}

	bool GameController::ColorizeYellow() {
		return m_keys[COLORIZE_YELLOW].PressDown();
	}
}