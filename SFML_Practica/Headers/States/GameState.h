#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "IState.h"
#include "Player.h"
#include "Asteroid/AsteroidPool.h"
#include "Controllers\GameController.h"

namespace state {
	class GameState : public IState {
	public:
		GameState(sf::View& view, const sf::Time* elapsed);
		virtual void Update(IState* pNextState);
	private:
		sf::View* m_pView;
		const sf::Time* m_pTime;
		player::Player* m_pPlayer;
		asteroidSys::AsteroidPool* m_pAsteroids;
		input::GameController m_gameController;
		virtual void StateLoop();
		void CheckInput();
	};
}
#endif // !GAME_STATE_H
