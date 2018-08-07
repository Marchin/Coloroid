#include "States/StateController.h"
#include "States/GameState.h"

namespace state {
	StateController::StateController(sf::RenderWindow* window,
		const sf::Time* time, IState* initialState)
		: m_pWindow(window), m_time(time){

		m_pCurrentState = new GameState(window, time);
		m_pNextState = m_pCurrentState;
	}

	StateController::~StateController() {
		if (m_pCurrentState != nullptr) {
			delete m_pCurrentState;
		}
		if (m_pNextState != nullptr && m_pNextState != m_pCurrentState) {
			delete m_pNextState;
		}
	}

	void StateController::Update() {
		m_pCurrentState->Update(m_pNextState, m_exitGame);
		if (m_pNextState != m_pCurrentState) {
			delete m_pCurrentState;
			m_pCurrentState = m_pNextState;
		}
	}
	bool StateController::HasEnded() const {
		return m_exitGame;
	}
}
