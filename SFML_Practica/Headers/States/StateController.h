#ifndef STATE_CONTROLLER_H
#define STATE_CONTROLLER_H

#include "IState.h"

namespace state {
	class StateController {
	public:
		StateController(sf::RenderWindow* window,
			const sf::Time* time, IState* initialState);
		~StateController();
		void Update();
		bool HasEnded() const;
	private:
		sf::RenderWindow* m_pWindow;
		const sf::Time const* m_time;
		IState* m_pCurrentState;
		IState* m_pNextState;
		bool m_exitGame;
	};
}
#endif // !STATE_CONTROLLER_H
