#ifndef ASTEROID_H
#define ASTEROID_H

#include "Sprites/ISprite.h"
#include "ColorExtension.h"
#define PI 3.14159265

namespace asteroidSys {
	class Asteroid : public ISprite {
	public:
		Asteroid();
		void Update(const float deltaTime);
		bool IsAvailable() const override;
		unsigned int Width() const override;
		unsigned int Height() const override;
		sf::Color GetColor() const override;
		void SetColor(const sf::Color& color) override;
		float GetDirection() const override;
		void SetDirection(const float angle) override;
		sf::Vector2f GetPosition() const override;
		void SetPosition(const sf::Vector2f& position) override;
		void Enable() override;
		void Disable() override;
		sf::Sprite GetSprite() const;
		void draw(sf::RenderTarget& target,
			sf::RenderStates states) const override;
	private:
		bool m_beingUsed;
		float m_speed;
		sf::Vector2f m_direction;
		sf::Texture m_texture;
		sf::Sprite m_sprite;
	};
}
#endif // !ASTEROID_H
