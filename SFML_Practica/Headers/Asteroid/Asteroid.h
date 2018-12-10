#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Audio.hpp>
#include "Sprites/ISprite.h"

namespace asteroidSys {

class Asteroid : public ISprite {
public:
	Asteroid();
	void Update(const float deltaTime);
	bool IsAvailable() const override;
	bool IsActive() const;
	float Width() const override;
	float Height() const override;
	sf::Color GetColor() const override;
	void SetColor(const sf::Color& color) override;
	float GetDirection() const override;
	void SetDirection(const float angle) override;
	void SetDirection(const sf::Vector2f& direction);
	sf::Vector2f GetPosition() const override;
	void SetPosition(const sf::Vector2f& position) override;
	void Enable() override;
	void Disable() override;
	void Destroy();
	sf::Sprite GetSprite() const;
	void draw(sf::RenderTarget& target,
		sf::RenderStates states) const override;
private:
	bool m_beingUsed;
	float m_speed;
	sf::Vector2f m_direction;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Sound m_asteroidSound;
	sf::SoundBuffer m_asteroidExplosionFX;
};

}
#endif // !ASTEROID_H
