#ifndef ASTEROID_POOL_H
#define ASTEROID_POOL_H

#include "Sprites/ISpritePool.h"
#include "Asteroid/Asteroid.h"

namespace asteroidSys {
	class AsteroidPool : public ISpritePool {
	public:
		AsteroidPool(const sf::View* pView, unsigned int amount);
		bool Request(const float angle, const sf::Color& color) override;
		void Update(const float deltaTime);
		void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	private:
		bool IsAvailable(ISprite*& pRequester) override;
		void ResetPosition(ISprite*& asteroid) override;
		bool OutOfBound(const ISprite* const& asteroid) const override;
		const sf::View* m_pView;
		std::vector<Asteroid> m_asteroids;
	};
}

#endif // !ASTEROID_POOL_H
