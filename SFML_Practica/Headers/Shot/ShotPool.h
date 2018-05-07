#pragma once
#include "Shot\Shot.h"
#define AMMO_AMOUNT 3
#define COLORS_AMOUNT 4

namespace shotSys {
	class ShotPool {
	public:
		ShotPool(const sf::View* pView);
		~ShotPool();
		void RequestShot(sf::Vector2f direction);
		void UpdateMovement(const std::array<sf::Sprite,0>& obstacles,
			const float deltaTime);
	private:
		bool IsShotAvailable(Shot*& availableShot);
		void ResetShotPosition(Shot& shot);
		bool OutOfBound(const Shot& shot);
		const sf::View* m_pView;
		std::array<Shot, AMMO_AMOUNT> m_shots;
		std::array<sf::Color, COLORS_AMOUNT> m_colors;
	};
}