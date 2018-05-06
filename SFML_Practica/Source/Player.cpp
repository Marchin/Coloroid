#include "Player.h"

namespace player {
	Player::Player() {
		if (!m_texture.loadFromFile("Resources\\Nave.png")) {
			printf("texture error");
		}
		m_sprite.setTexture(m_texture);
		m_sprite.setOrigin(Width()/2, Height()/2);
	}

	Player::Player(sf::Vector2f vec) {
		Player();
		m_sprite.move(vec);
	}

	sf::Sprite Player::GetPlayer() {
		return m_sprite;
	}

	void Player::Rotate(float angle, const float deltaTime) {
		m_sprite.rotate(angle * deltaTime);
	}

	void Player::Move(sf::Vector2f movement, const float deltaTime) {
		m_sprite.move(movement * deltaTime);
	}

	float Player::Width() {
		return m_sprite.getLocalBounds().width;
	}

	float Player::Height() {
		return m_sprite.getLocalBounds().width;
	}
}