#ifndef ASTEROID_H
#define ASTEROID_H

#include "Sprites/ISprite.h"
#include "ColorExtension.h"
#define PI 3.14159265

namespace asteroidSys {
	class Asteroid : ISprite {
	public:
		Asteroid();
		void Update(const float deltaTime);
		bool IsAvailable() const;
		unsigned int Width() const;
		unsigned int Height() const;
		sf::Color GetColor() const;
		sf::Sprite GetDrawable() const;
		void SetColor(const sf::Color& color);
		void SetDirection(const float angle);
		void SetPosition(const sf::Vector2f& position);
		void Enable();
		void Disable();
	private:
		bool m_available;
		float m_speed;
		sf::Vector2f m_direction;
		sf::Texture m_texture;
		sf::Sprite m_sprite;
	};
}
#endif // !ASTEROID_H
