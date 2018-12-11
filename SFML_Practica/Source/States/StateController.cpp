#include "States/StateController.h"
#include "States/GameState.h"
#include "States/StartState.h"
#include "States/EndState.h"

namespace state {

	StateController::StateController(sf::RenderWindow *pWindow, const sf::Time* pTime)
		: m_pWindow(pWindow), m_time(pTime) {

		m_pCurrentState = new StartState(pWindow, pTime);
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
		m_pCurrentState->Update(&m_pNextState, m_exitGame);
		if (m_pNextState != m_pCurrentState) {
			delete m_pCurrentState;
			m_pCurrentState = m_pNextState;
		}
	}
	bool StateController::HasEnded() const { return m_exitGame; }

} // namespace state
