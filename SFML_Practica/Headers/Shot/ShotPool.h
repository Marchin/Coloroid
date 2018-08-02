#ifndef SHOT_POOL_H
#define SHOOT_POOL_H

#include "Shot/Shot.h"
#define AMMO_AMOUNT 3

namespace shotSys {
	class ShotPool {
	public:
		ShotPool(const sf::View* pView) : m_pView(pView) {}
		~ShotPool() {}
		std::array<sf::Sprite, AMMO_AMOUNT> GetDrawables();
		void RequestShot(const float& angle, const sf::Color& color);
		void Update(const std::array<sf::Sprite,0>& obstacles,
			const float& deltaTime);
	private:
		bool IsShotAvailable(Shot*& pShotRequester);
		void ResetShotPosition(Shot& shot);
		bool OutOfBound(const Shot& shot);
		const sf::View* m_pView;
		std::array<Shot, AMMO_AMOUNT> m_shots;
	};
}

#endif // !SHOT_POOL_H
