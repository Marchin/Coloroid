#ifndef SHOT_H
#define SHOT_H

#include "Sprites/ISprite.h"
#include "ColorExtension.h"
#include "Collision.h"
#define PI 3.14159265

namespace asteroidSys {
	class AsteroidPool;
}

namespace shotSys {
	class Shot : public ISprite{
	public:
		Shot();
		void Update(asteroidSys::AsteroidPool& obstacles,
			const float deltaTime);
		float GetDirection() const override;
		void SetDirection(const float angle) override;
		sf::Color GetColor() const override;
		void SetColor(const sf::Color& color) override;
		bool IsAvailable() const override;
		void draw(sf::RenderTarget& target,
			sf::RenderStates states) const override;
		sf::Vector2f GetPosition() const override;
		void SetPosition(const sf::Vector2f& position) override;
		void Enable() override;
		void Disable() override;
		unsigned int Width() const override;
		unsigned int Height() const override;
	private:
		void CheckCollision(asteroidSys::AsteroidPool& obstacles);
		float m_speed;
		bool m_beingFired;
		sf::Vector2f m_direction; 
		sf::Sprite m_sprite;
		sf::Texture m_texture;
	};
}
#endif // !SHOT_H
