#pragma once
#include <SFML\Graphics.hpp>
#include <array>
#include "ColorExtension.h"
#include "Collision.h"

namespace shotSys {
	class Shot {
	public:
		Shot();
		void UpdateMovement(const std::array<sf::Sprite,0>& obstacles, const float deltaTime);
		void SetDirection(sf::Vector2f direction);
		sf::Color GetColor() const;
		void SetColor(sf::Color color);
		bool IsAvailable();
		sf::Vector2f GetPosition() const;
		void SetPosition(sf::Vector2f position);
		void Enable();
		void Disable();
		float Width() const;
		float Height() const;
	private:
		void CheckCollision(const std::array<sf::Sprite,0>& obstacles);
		float m_speed;
		bool m_beingFired;
		sf::Vector2f m_direction; 
		sf::Sprite m_sprite;
		sf::Texture m_texture;
	};
}