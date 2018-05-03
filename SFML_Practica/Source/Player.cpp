#include "Player.h"

namespace player {
	Player::Player() {

		if (!playerTexture.loadFromFile("Resources\\Nave.png")) {
			printf("texture error");
		}

		playerSprite.setTexture(playerTexture);
		playerSprite.setOrigin(Width()/2, Height()/2);
	}


	Player::Player(sf::Vector2f vec) {
		Player();
		playerSprite.move(vec);
	}

	sf::Sprite Player::GetPlayer() {
		return playerSprite;
	}

	void Player::Rotate(float angle, const float deltaTime) {
		playerSprite.rotate(angle * deltaTime);
	}

	void Player::Move(sf::Vector2f movement, float deltaTime) {
		playerSprite.move(movement * deltaTime);
	}

	float Player::Width() {
		return playerSprite.getLocalBounds().width;
	}

	float Player::Height() {
		return playerSprite.getLocalBounds().width;
	}
}