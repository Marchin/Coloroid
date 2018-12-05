#include "Player.h"
#include "Constants.h"
#include "ColorExtension.h"

namespace player {

Player::Player(const sf::Vector2f& position, const sf::View* pView) 
	: m_lifes(constant::LIFES), m_pView(pView) {

	if (!m_texture.loadFromFile("Resources\\Ship.png")) {
		printf("texture error");
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(Width() / 2, Height() / 2);
	m_sprite.move(position);
	m_sprite.setColor(sf::Color::Blue);
	m_pAmmo = new shotSys::ShotPool(m_pView, constant::LIFES);
}

Player::~Player() {
	delete m_pAmmo;
}

void Player::SetColor(const sf::Color& color) {
	m_sprite.setColor(color);
}

sf::Vector2f Player::GetPosition() const {
	return m_sprite.getPosition();
}

void Player::Rotate(const float turnRate, const float deltaTime) {
	m_sprite.rotate(turnRate * deltaTime);
}

void Player::Fire() {
	m_pAmmo->Request(m_sprite.getRotation(), m_sprite.getColor());
}

shotSys::ShotPool* Player::GetShots() {
	return m_pAmmo;
}

void Player::UpdateShots(const float deltaTime) {

	m_pAmmo->Update(deltaTime);
}

float Player::Width() const{
	return m_sprite.getLocalBounds().width;
}

float Player::Height() const {
	return m_sprite.getLocalBounds().width;
}

void Player::TakeDamage() {
	m_lifes--;
	if (m_lifes == 0) {
		//fin del juego
		SetColor(color::Transparent(m_sprite.getColor()));
	}
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