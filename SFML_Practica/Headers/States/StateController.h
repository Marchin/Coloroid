#ifndef STATE_CONTROLLER_H
#define STATE_CONTROLLER_H

#include "IState.h"

namespace state {
	class StateController {
	public:
		StateController(sf::RenderWindow& window);
		~StateController();
		void Update();
		bool HasEnded() const;

	private:
		void NextState(IState* pNextState);
		IState * m_pCurrentState;
		IState * m_pPreviousState;
		bool m_finished;
	};
}
#endif // !STATE_CONTROLLER_H
