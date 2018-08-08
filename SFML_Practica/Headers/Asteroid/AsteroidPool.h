#ifndef ASTEROID_POOL_H
#define ASTEROID_POOL_H

#include "Sprites/ISpritePool.h"
#include "Asteroid/Asteroid.h"

namespace asteroidSys {
	class AsteroidPool : public ISpritePool {
	public:
		AsteroidPool(const sf::View* pView,
			unsigned int amount, float interval);
		bool Request(const float angle, const sf::Color& color,
			Asteroid** requested = nullptr);
		void Update(const float deltaTime);
		Asteroid operator[](unsigned int index);
		unsigned int GetSize() const;
	private:
		void draw(sf::RenderTarget& target,
			sf::RenderStates states) const ;
		bool IsAvailable(ISprite*& pRequester) override;
		void ResetPosition(ISprite*& asteroid) override;
		bool OutOfBound(const ISprite* const& asteroid) const override;
		const sf::View* m_pView;
		std::vector<Asteroid> m_asteroids;
		const float m_interval;
		float m_counter;
	};
}

#endif // !ASTEROID_POOL_H
