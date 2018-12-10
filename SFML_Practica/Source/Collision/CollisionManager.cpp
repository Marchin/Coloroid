#include "Collision/CollisionManager.h"
#include "Collision/Collision.h"

namespace Collision {

	CollisionManager::CollisionManager(player::Player* pPlayer,
		shotSys::ShotPool* pShots, asteroidSys::AsteroidPool* pAsteroids)
		: m_pPlayer(pPlayer), m_pShots(pShots), m_pAsteroids(pAsteroids) {
	}

	void CollisionManager::Update() {
		for (unsigned int iAsteroid = 0;
			iAsteroid < m_pAsteroids->GetSize(); iAsteroid++) {
			if ((*m_pAsteroids)[iAsteroid]->IsActive()) {

				if (Collision::CircleTest(m_pPlayer->GetSprite(),
					(*m_pAsteroids)[iAsteroid]->GetSprite())) {

					m_pPlayer->TakeDamage();
					(*m_pAsteroids)[iAsteroid]->Disable();
				}
				for (unsigned int iShot = 0; iShot < m_pShots->GetSize(); iShot++) {
					if ((*m_pShots)[iShot]->IsActive()) {

						if (Collision::CircleTest((*m_pShots)[iShot]->GetSprite(),
							(*m_pAsteroids)[iAsteroid]->GetSprite())) {

							if ((*m_pShots)[iShot]->GetColor() ==
								(*m_pAsteroids)[iAsteroid]->GetColor()) {

								(*m_pAsteroids)[iAsteroid]->Destroy();
							}
							(*m_pShots)[iShot]->Disable();
							break;
						}
					}
				}
			}
		}
	}

}
