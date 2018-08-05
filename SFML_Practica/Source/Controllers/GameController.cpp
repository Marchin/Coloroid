#include "Controllers\GameController.h"
#include <functional>

namespace input {
	GameController::GameController(){
		using namespace sf;
		auto reader = &Keyboard::isKeyPressed;
		m_keys.push_back((new Input(reader, Keyboard::Space)));
		m_keys.push_back((new Input(reader, Keyboard::Left)));
		m_keys.push_back((new Input(reader, Keyboard::Right)));
		m_keys.push_back((new Input(reader, Keyboard::A)));
		m_keys.push_back((new Input(reader, Keyboard::S)));
		m_keys.push_back((new Input(reader, Keyboard::D)));
		m_keys.push_back((new Input(reader, Keyboard::F)));
	}

	GameController::~GameController() {
		for (unsigned int i = 0; i < m_keys.size(); i++) {
			delete m_keys[i];
		}
	}

	void GameController::UpdateKeys() {
		for (unsigned int i = 0; i < m_keys.size(); i++) {
			m_keys[i]->Update();
		}
	}

	bool GameController::Fire() {
		return m_keys[FIRE]->PressDown();
	}

	bool GameController::RotateLeft() {
		return m_keys[ROTATE_LEFT]->IsPressed();
	}

	bool GameController::RotateRight() {
		return m_keys[ROTATE_RIGHT]->IsPressed();
	}

	bool GameController::ColorizeBlue() {
		return m_keys[COLORIZE_BLUE]->PressDown();
	}

	bool GameController::ColorizeRed() {
		return m_keys[COLORIZE_RED]->PressDown();
	}

	bool GameController::ColorizeGreen() {
		return m_keys[COLORIZE_GREEN]->PressDown();
	}

	bool GameController::ColorizeYellow() {
		return m_keys[COLORIZE_YELLOW]->PressDown();
	}
}