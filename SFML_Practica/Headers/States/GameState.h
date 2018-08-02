#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "IState.h"
#include "Player.h"
#include "Controllers\GameController.h"

namespace state {
	class GameState : public IState {
	public:
		GameState(sf::RenderWindow& window);
		virtual void Update(IState* pNextState);
	private:
		IState* m_pNextState;
		sf::RenderWindow* m_pWindow;
		player::Player* m_pPlayer;
		input::GameController m_gameController;
		virtual void StateLoop();
		void CheckInput();
	};
}
#endif // !GAME_STATE_H
