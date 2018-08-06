#include "Asteroid/Asteroid.h"

namespace asteroidSys {
	Asteroid::Asteroid()
		: m_speed(0.f), m_direction(sf::Vector2f(0.f, 0.f)) {

		if (!m_texture.loadFromFile("../SFML_Practica/Resources/Asteroid.png")) {
			printf("texture error");
		}
		m_sprite.setTexture(m_texture);
		m_sprite.setOrigin((float)Width() / 2, (float)Height() / 2);
		m_sprite.setColor(color::Transparent(sf::Color::Blue));
	}

	void Asteroid::Update(const float deltaTime) {
		if (m_beingUsed) {
			m_sprite.move(m_direction * m_speed * deltaTime);
		}
	}

	bool Asteroid::IsAvailable() const {
		return m_beingUsed;
	}

	unsigned int Asteroid::Width() const {
		return m_texture.getSize().x;
	}

	unsigned int Asteroid::Height() const {
		return m_texture.getSize().y;
	}

	sf::Color Asteroid::GetColor() const {
		return m_sprite.getColor();
	}

	void Asteroid::SetColor(const sf::Color& color) {
		m_sprite.setColor(color);
	}

	float Asteroid::GetDirection() const {
		return m_sprite.getRotation();
	}

	void Asteroid::SetDirection(const float angle) {
		m_sprite.setRotation(angle);
		sf::Vector2f direction = sf::Vector2f(
			(float)std::sin(angle * PI / 180.f), (float)-std::cos(angle * PI / 180.f));
		m_direction = direction;

	}

	sf::Vector2f Asteroid::GetPosition() const {
		return m_sprite.getPosition();
	}

	void Asteroid::SetPosition(const sf::Vector2f & position) {
		m_sprite.setPosition(position);
	}

	void Asteroid::Enable() {
		m_beingUsed = true;
	}

	void Asteroid::Disable() {
		m_beingUsed = false;
		m_sprite.setColor(color::Transparent(m_sprite.getColor()));
	}

	void Asteroid::draw(sf::RenderTarget& target,
		sf::RenderStates states) const {

		if (m_beingUsed) {
			target.draw(m_sprite, states);
		}
	}
}