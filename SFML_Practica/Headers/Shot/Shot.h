#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "ColorExtension.h"
#include "Collision.h"

namespace shot {
	class Shot {
	public:
		Shot();
		void UpdateMovement(const std::vector<sf::Sprite>& obstacles, const float deltaTime);
		void SetDirection(sf::Vector2f direction);
		sf::Color GetColor() const;
		void SetColor(sf::Color color);
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