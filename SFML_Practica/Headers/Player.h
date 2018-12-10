#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Shot/ShotPool.h"

namespace player {

class Player : public sf::Drawable{
public:
	Player(const sf::Vector2f& position, const sf::View* pView);
	~Player();
	void SetColor(const sf::Color& color);
	sf::Vector2f GetPosition() const;
	void Rotate(const float turnRate, const float deltaTime = 1.f);
	void Fire();
	shotSys::ShotPool* GetShots();
	void Update(const float deltaTime = 1.f);
	float Width() const;
	float Height() const;
	int GetLifes();
	void TakeDamage();
	sf::Sprite GetSprite() const;
private:
	virtual void draw(sf::RenderTarget& target, 
						sf::RenderStates states) const;
	int m_lifes;
	const float m_INVI_DURATION;
	float m_inviCounter;
	shotSys::ShotPool* m_pAmmo;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Color m_color;
	sf::Sound m_shipSound;
	sf::SoundBuffer m_explosionFX;
	sf::SoundBuffer m_shotFX;
	const sf::View* m_pView;

};
}
#endif // !PLAYER_H
