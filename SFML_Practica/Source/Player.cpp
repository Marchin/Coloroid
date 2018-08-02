#include "Player.h"

namespace player {
	Player::Player(const sf::Vector2f& position, const sf::View* pView) {
		if (!m_texture.loadFromFile("Resources\\Nave.png")) {
			printf("texture error");
		}
		m_sprite.setTexture(m_texture);
		m_sprite.setOrigin(Width() / 2, Height() / 2);
		m_sprite.move(position);
		m_sprite.setColor(sf::Color::Blue);
		m_pView = pView;
		m_pAammo = new shotSys::ShotPool(m_pView);
	}

	Player::~Player() {
		delete m_pAammo;
	}

	void Player::SetColor(const sf::Color& color) {
		m_sprite.setColor(color);
	}

	void Player::Rotate(const float& angle, const float& deltaTime) {
		m_sprite.rotate(angle * deltaTime);
	}

	void Player::Fire() {
		m_pAammo->RequestShot(m_sprite.getRotation(), m_sprite.getColor());
	}

	void Player::UpdateShots(const std::array<sf::Sprite, 0>& obstacles,
		const float& deltaTime) {

		m_pAammo->Update(obstacles, deltaTime);
		shotSprites = m_pAammo->GetDrawables();
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