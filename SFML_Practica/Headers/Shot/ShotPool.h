#pragma once
#include "Shot\Shot.h"
#define AMMO_AMOUNT 3
#define COLORS_AMOUNT 4

namespace shot {
	class ShotPool {
	public:
		ShotPool(sf::View* pView);
		void RequestShot(sf::Vector2f direction);
		void UpdateMovement(const std::vector<sf::Sprite>& obstacles,
			const float deltaTime);
	private:
		bool IsShotAvailable(Shot* availableShot);
		void ResetShotPosition(Shot& shot);
		bool OutOfBound(const Shot& shot);
		sf::View* m_pView;
		std::vector<Shot> m_shots;
		std::vector<sf::Color> m_colors;
	};
}