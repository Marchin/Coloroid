#include "Player.h"
#include "Constants.h"
#include "ColorExtension.h"

namespace player {

Player::Player(const sf::Vector2f& position, const sf::View* pView) 
	: m_lifes(constant::LIFES), m_pView(pView), m_INVI_DURATION(0.2f), m_inviCounter(0.f) {

	if (!m_texture.loadFromFile("Resources/Ship.png")) {
		printf("Error: fail loading ships's texture");
	}
	if (!m_explosionFX.loadFromFile("Resources/ExplosionShip.wav")) {
		printf("Error: fail loading explosion sound");
	}
	if (!m_shotFX.loadFromFile("Resources/Shot.wav")) {
		printf("Error: fail loading shot sound");
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(Width() / 2, Height() / 2);
	m_sprite.setPosition(position);
	m_sprite.setColor(sf::Color::Blue);
	m_pAmmo = new shotSys::ShotPool(m_pView, constant::LIFES);
}

Player::~Player() {
	delete m_pAmmo;
}

void Player::SetColor(const sf::Color& color) {
	if (m_inviCounter > 0.f) {
		m_sprite.setColor(color::Transparent(color));
	} else {
		m_sprite.setColor(color);
	}
}

sf::Vector2f Player::GetPosition() const {
	return m_sprite.getPosition();
}

void Player::Rotate(const float turnRate, const float deltaTime) {
	m_sprite.rotate(turnRate * deltaTime);
}

void Player::Fire() {
	if (m_pAmmo->Request(m_sprite.getRotation(), m_sprite.getColor())) {
		m_shipSound.setBuffer(m_shotFX);
		m_shipSound.play();
	}
}

shotSys::ShotPool* Player::GetShots() {
	return m_pAmmo;
}

void Player::Update(const float deltaTime) {
	m_pAmmo->Update(deltaTime);
	if (m_inviCounter > 0.f) {
		m_inviCounter -= deltaTime;
		if (m_inviCounter <= 0.f) {
			SetColor(color::Opaque(m_sprite.getColor()));
		}
	}
}

float Player::Width() const{
	return m_sprite.getLocalBounds().width;
}

float Player::Height() const {
	return m_sprite.getLocalBounds().width;
}

int Player::GetLifes() {
	return m_lifes;
}

void Player::TakeDamage() {
	m_shipSound.setBuffer(m_explosionFX);
	m_shipSound.play();
	SetColor(color::Transparent(m_sprite.getColor()));
	m_inviCounter = m_INVI_DURATION;
	m_lifes--;
}

sf::Sprite Player::GetSprite() const {
	return m_sprite;
}

void Player::draw(sf::RenderTarget & target,
	sf::RenderStates states) const {

	target.draw(m_sprite, states);
	m_pAmmo->draw(target, states);
}

}