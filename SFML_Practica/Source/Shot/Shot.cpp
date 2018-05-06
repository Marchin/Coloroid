#include "Shot\Shot.h"

namespace shot {
	Shot::Shot() {
		if (!m_texture.loadFromFile("Resources\\Shot.png")) {
			printf("texture error");
		}
		m_sprite.setTexture(m_texture);
		m_sprite.setOrigin(Width() / 2, Height() / 2);
		m_sprite.setColor(color::Transparent(sf::Color::Blue));
		m_speed = 1.f;
		m_direction = sf::Vector2f(0.f, 0.f);
		m_beingFired = false;
	}

	float Shot::Width() {
		return m_sprite.getLocalBounds().width;
	}

	float Shot::Height() {
		return m_sprite.getLocalBounds().width;
	}

	void Shot::UpdateMovement(const float deltaTime) {
		if (m_beingFired) {
			m_sprite.move(m_direction * m_speed * deltaTime);
		}
	}

	void Shot::SetDirection(sf::Vector2f direction) {
		m_direction = direction;
	}
	sf::Color Shot::GetColor() {
		return m_sprite.getColor();
	}
	void Shot::SetColor(sf::Color color) {
		m_sprite.setColor(color);
	}
}