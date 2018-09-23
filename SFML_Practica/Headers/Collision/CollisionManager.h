#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "Shot/ShotPool.h"
#include "Asteroid/AsteroidPool.h"
#include "Player.h"

namespace Collision {
	class CollisionManager {
	public:
		CollisionManager(player::Player* pPlayer, shotSys::ShotPool* ´Shots,
			asteroidSys::AsteroidPool* pAsteroids);
		void Update();

	private:
		player::Player* m_pPlayer;
		shotSys::ShotPool* m_pShots;
		asteroidSys::AsteroidPool* m_pAsteroids;
	};
}
#endif // !COLLISION_MANAGER_H