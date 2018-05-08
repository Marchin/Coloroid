#include "Player.h"

namespace player {
	Player::Player(sf::Vector2f position, const sf::View* pView) {
		if (!m_texture.loadFromFile("Resources\\Nave.png")) {
			printf("texture error");
		}
		m_sprite.setTexture(m_texture);
		m_sprite.setOrigin(Width() / 2, Height() / 2);
		m_sprite.move(position);
		m_sprite.setColor(sf::Color::Blue);
		m_pView = pView;
		m_ammo = new shotSys::ShotPool(m_pView);
	}

	Player::~Player() {
		delete m_ammo;
	}

	void Player::SetColor(sf::Color color) {
		m_sprite.setColor(color);
	}

	void Player::Rotate(float angle, const float deltaTime) {
		m_sprite.rotate(angle * deltaTime);
	}

	void Player::Move(sf::Vector2f movement, const float deltaTime) {
		m_sprite.move(movement * deltaTime);
	}

	void Player::Fire() {
		m_ammo->RequestShot(m_sprite.getRotation(), m_sprite.getColor());
	}

	void Player::UpdateShots(const std::array<sf::Sprite, 0>& obstacles,
		const float deltaTime) {

		m_ammo->Update(obstacles, deltaTime);
		shotSprites = m_ammo->GetDrawables();
	}

	float Player::Width() const{
		return m_sprite.getLocalBounds().width;
	}

	float Player::Height() const {
		return m_sprite.getLocalBounds().width;
	}

	void Player::draw(sf::RenderTarget & target,
		sf::RenderStates states) const {

		target.draw(m_sprite, states);
		for (sf::Sprite shotSprite : shotSprites) {
			target.draw(shotSprite, states);
		}
	}
}