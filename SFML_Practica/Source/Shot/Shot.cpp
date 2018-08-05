#include "Shot\Shot.h"

namespace shotSys {
	Shot::Shot()
		: m_speed(100.f), m_direction(sf::Vector2f(0.f, 0.f)),
		m_beingFired(false) {

		if (!m_texture.loadFromFile("../SFML_Practica/Resources/Shot.png")) {
			printf("texture error");
		}
		m_sprite.setTexture(m_texture);
		m_sprite.setOrigin((float)Width() / 2, (float)Height() / 2);
		m_sprite.setColor(color::Transparent(sf::Color::Blue));
	}

	unsigned int Shot::Width() const{
		return m_sprite.getLocalBounds().width;
	}

	unsigned int Shot::Height() const{
		return m_sprite.getLocalBounds().height;
	}

	void Shot::Update(const std::vector<sf::Sprite>& obstacles,
							const float deltaTime) {
		if (m_beingFired) {
			m_sprite.move(m_direction * m_speed * deltaTime);
			CheckCollision(obstacles);
		}
	}

	float Shot::GetDirection() const {
		return m_sprite.getRotation();
	}

	void Shot::SetDirection(const float angle) {
		m_sprite.setRotation(angle);
		sf::Vector2f direction = sf::Vector2f(
			std::sin(angle * PI/180.f),-std::cos(angle * PI/180.f));
		m_direction = direction;
	}

	void Shot::CheckCollision(const std::vector<sf::Sprite>& obstacles) {
		for (int i = 0; obstacles.size(); i++) {
			if (Collision::CircleTest(m_sprite, obstacles[i])) {
				if (m_sprite.getColor() == obstacles[i].getColor()) {
					//destroy asteroid
				}
				Disable();
			}
		}
	}

	void Shot::Disable() {
		m_sprite.setColor(color::Transparent(m_sprite.getColor()));
		m_beingFired = false;
	}

	void Shot::Enable() {
		m_beingFired = true;
	}

	void Shot::SetPosition(const sf::Vector2f& position) {
		m_sprite.setPosition(position);
	}

	sf::Vector2f Shot::GetPosition() const {
		return m_sprite.getPosition();
	}

	sf::Color Shot::GetColor() const{
		return m_sprite.getColor();
	}

	void Shot::SetColor(const sf::Color& color) {
		m_sprite.setColor(color);
	}

	bool Shot::IsAvailable() const{
		return !m_beingFired;
	}

	void Shot::draw(sf::RenderTarget & target,
		sf::RenderStates states) const {

		target.draw(m_sprite, states);
	}
}