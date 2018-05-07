#include "Player.h"

namespace player {
	Player::Player(sf::Vector2f position, const sf::View* pView) {
		if (!m_texture.loadFromFile("Resources\\Nave.png")) {
			printf("texture error");
		}
		m_sprite.setTexture(m_texture);
		m_sprite.setOrigin(Width() / 2, Height() / 2);
		m_sprite.move(position);
		m_pView = pView;
		m_ammo = new shotSys::ShotPool(m_pView);
	}

	Player::~Player() {
		delete m_ammo;
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

	void Player::Fire() {
		sf::Vector2f shotDirection(
			std::sin(m_sprite.getRotation()),
			std::cos(m_sprite.getRotation())
			);
		m_ammo->RequestShot(shotDirection);
	}

	void Player::UpdateShotsMovement(const std::array<sf::Sprite, 0>& obstacles,
		const float deltaTime) {

		m_ammo->UpdateMovement(obstacles, deltaTime);
	}

	float Player::Width() const{
		return m_sprite.getLocalBounds().width;
	}

	float Player::Height() const {
		return m_sprite.getLocalBounds().width;
	}
}