#ifndef SHOT_POOL_H
#define SHOOT_POOL_H

#include "Shot/Shot.h"

namespace shotSys {
	class ShotPool {
	public:
		ShotPool(const sf::View* pView, unsigned int amount);
		~ShotPool() {}
		bool RequestShot(const float angle, const sf::Color& color);
		void Update(const float deltaTime,
			const std::vector<sf::Sprite>& obstacles);
		void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	private:
		bool IsShotAvailable(Shot*& pShotRequester);
		void ResetShotPosition(Shot& shot);
		bool OutOfBound(const Shot& shot);
		const sf::View* m_pView;
		std::vector<Shot> m_shots;
	};
}

#endif // !SHOT_POOL_H
