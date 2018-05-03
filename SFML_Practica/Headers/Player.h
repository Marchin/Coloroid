#pragma once
#include <SFML/Graphics.hpp>

namespace player {
	class Player {
	public:
		Player();
		Player(sf::Vector2f);
		sf::Sprite GetPlayer();
		void Rotate(float angle,const float deltaTime = 1.f);
		void Move(sf::Vector2f, float deltaTime = 1.f);
		float Width();
		float Height();
	private:
		sf::Texture playerTexture;
		sf::Sprite playerSprite;
	};
}