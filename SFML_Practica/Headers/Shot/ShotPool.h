#ifndef SHOT_POOL_H
#define SHOOT_POOL_H

#include "Sprites/ISpritePool.h"
#include "Shot/Shot.h"

namespace shotSys {
	class ShotPool : public ISpritePool{
	public:
		ShotPool(const sf::View* pView, unsigned int amount);
		bool Request(const float angle, const sf::Color& color) override;
		void Update(const float deltaTime,
			asteroidSys::AsteroidPool& obstacles);
		void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	private:
		bool IsAvailable(ISprite*& pRequester) override;
		void ResetPosition(ISprite*& shot) override;
		bool OutOfBound(const ISprite* const& shot) const override;
		const sf::View* m_pView;
		std::vector<Shot> m_shots;
	};
}

#endif // !SHOT_POOL_H
