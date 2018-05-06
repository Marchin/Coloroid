#pragma once
#include <SFML\Graphics.hpp>
#include "ColorExtension.h"

namespace shot {
	class Shot {
	public:
		Shot();
		void UpdateMovement(const float deltaTime);
		void SetDirection(sf::Vector2f direction);
		sf::Color GetColor();
		void SetColor(sf::Color color);
		float Width();
		float Height();
	private:
		float m_speed;
		bool m_beingFired;
		sf::Vector2f m_direction;
		sf::Sprite m_sprite;
		sf::Texture m_texture;
	};
}