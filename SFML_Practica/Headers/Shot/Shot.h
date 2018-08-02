#ifndef SHOT_H
#define SHOT_H

#include <SFML/Graphics.hpp>
#include "ColorExtension.h"
#include "Collision.h"
#define PI 3.14159265

namespace shotSys {
	class Shot {
	public:
		Shot();
		void Update(const std::vector<sf::Sprite>& obstacles,
			const float& deltaTime);
		void SetDirection(const float& angle);
		sf::Color GetColor() const;
		void SetColor(const sf::Color& color);
		bool IsAvailable() const;
		void draw(sf::RenderTarget & target, sf::RenderStates states) const;
		sf::Vector2f GetPosition() const;
		sf::Sprite GetDrawable() const;
		void SetPosition(const sf::Vector2f& position);
		void Enable();
		void Disable();
		float Width() const;
		float Height() const;
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
