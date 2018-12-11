#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "IState.h"
#include "Player.h"
#include "Asteroid/AsteroidPool.h"
#include "Controllers/GameController.h"

namespace Collision {

class CollisionManager;

}

namespace state {

class GameState : public IState {
public:
	GameState(sf::RenderWindow* window, const sf::Time* elapsed);
	~GameState();
	void Update(IState** pNextState, bool& exitGame) override;
private:
	void CheckInput();
	void UpdateAsteroids();
	sf::Texture m_indicatorImage;
	sf::Sprite m_indicators[4];
	sf::RenderWindow* m_pWindow;
	const sf::Time* const m_pTime;
	player::Player* m_pPlayer;
	asteroidSys::AsteroidPool* m_pAsteroids;
	Collision::CollisionManager* m_pColManager;
	input::GameController m_gameController;
	sf::Text m_lifeText;
	sf::Text m_scoreText;
	sf::Font m_font;
	int m_score;
};

}
#endif // !GAME_STATE_H
