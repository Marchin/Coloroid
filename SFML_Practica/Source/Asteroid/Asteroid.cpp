#include "Asteroid/Asteroid.h"

asteroidSys::Asteroid::Asteroid()
	: m_speed(0.f), m_direction(sf::Vector2f(0.f, 0.f)) {

	if (!m_texture.loadFromFile("Resources\\Asteroid.png")) {
		printf("texture error");
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin((float)Width() / 2, (float)Height() / 2);
	m_sprite.setColor(color::Transparent(sf::Color::Blue));
}

void asteroidSys::Asteroid::Update(const float deltaTime) {
	if (m_available) {
		m_sprite.move(m_direction * m_speed * deltaTime);
	}
}

bool asteroidSys::Asteroid::IsAvailable() const {
	return m_available;
}

unsigned int asteroidSys::Asteroid::Width() const {
	return m_texture.getSize().x;
}

unsigned int asteroidSys::Asteroid::Height() const {
	return m_texture.getSize().y;
}

sf::Color asteroidSys::Asteroid::GetColor() const {
	return m_sprite.getColor();
}

sf::Sprite asteroidSys::Asteroid::GetDrawable() const {
	return m_sprite;
}

void asteroidSys::Asteroid::SetColor(const sf::Color& color) {
	m_sprite.setColor(color);
}

void asteroidSys::Asteroid::SetDirection(const float angle) {
	m_sprite.setRotation(angle);
	sf::Vector2f direction = sf::Vector2f(
		(float)std::sin(angle * PI / 180.f), (float)-std::cos(angle * PI / 180.f));
	m_direction = direction;

}

void asteroidSys::Asteroid::SetPosition(const sf::Vector2f & position) {
	m_sprite.setPosition(position);
}

void asteroidSys::Asteroid::Enable() {
	m_available = true;
}

void asteroidSys::Asteroid::Disable() {
	m_available = false;
	m_sprite.setColor(color::Transparent(m_sprite.getColor()));
}
