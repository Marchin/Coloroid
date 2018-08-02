#include "States\GameState.h"

namespace state {
	GameState::GameState(sf::RenderWindow& window) {
		m_pNextState = this;
		m_pWindow = &window;
		sf::Vector2f screenCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);
		//m_player.Move(screenCenter);
	}
	void GameState::Update(IState* pNextState) {
		StateLoop();

		if (pNextState != m_pNextState) {
			delete pNextState;
			pNextState = m_pNextState;
		}
	}

	void GameState::StateLoop() {
		CheckInput();
	}

	void GameState::CheckInput() {

	}
}