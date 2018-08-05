#ifndef SHOT_H
#define SHOT_H

#include "Sprites/ISprite.h"
#include "ColorExtension.h"
#include "Collision.h"
#define PI 3.14159265

namespace shotSys {
	class Shot : public ISprite{
	public:
		Shot();
		void Update(const std::vector<sf::Sprite>& obstacles,
			const float deltaTime) override;
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
		void CheckCollision(const std::vector<sf::Sprite>& obstacles);
		float m_speed;
		bool m_beingFired;
		sf::Vector2f m_direction; 
		sf::Sprite m_sprite;
		sf::Texture m_texture;
	};
}
#endif // !SHOT_H
