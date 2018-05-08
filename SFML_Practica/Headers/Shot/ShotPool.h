#pragma once
#include "Shot\Shot.h"
#define AMMO_AMOUNT 3

namespace shotSys {
	class ShotPool {
	public:
		ShotPool(const sf::View* pView);
		~ShotPool();
		std::array<sf::Sprite, AMMO_AMOUNT> GetDrawables();
		void RequestShot(const float& angle, sf::Color color);
		void Update(const std::array<sf::Sprite,0>& obstacles,
			const float& deltaTime);
	private:
		bool IsShotAvailable(Shot*& shotRequester);
		void ResetShotPosition(Shot& shot);
		bool OutOfBound(const Shot& shot);
		const sf::View* m_pView;
		std::array<Shot, AMMO_AMOUNT> m_shots;
	};
}