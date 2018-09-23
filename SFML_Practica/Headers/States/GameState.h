#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "IState.h"
#include "Player.h"
#include "Asteroid/AsteroidPool.h"
#include "Controllers\GameController.h"
namespace Collision {
	class CollisionManager;
}

namespace state {
	class GameState : public IState {
	public:
		GameState(sf::RenderWindow* window, const sf::Time* elapsed);
		~GameState();
		void Update(IState* pNextState, bool& exitGame) override;
	private:
		void CheckInput();
		void UpdateAsteroids();
		sf::RenderWindow* m_pWindow;
		const sf::Time* const m_time;
		player::Player* m_pPlayer;
		asteroidSys::AsteroidPool* m_pAsteroids;
		Collision::CollisionManager* m_pColManager;
		input::GameController m_gameController;
	};
}
#endif // !GAME_STATE_H
