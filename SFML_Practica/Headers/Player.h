#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Shot/ShotPool.h"

namespace player {
	class Player : public sf::Drawable{
	public:
		Player(const sf::Vector2f& position, const sf::View* pView);
		~Player();
		void SetColor(const sf::Color& color);
		sf::Vector2f GetPosition() const;
		void Rotate(const float angle, const float deltaTime = 1.f);
		void Fire();
		void UpdateShots(
			asteroidSys::AsteroidPool& obstacles,
			const float deltaTime = 1.f);
		float Width() const;
		float Height() const;
	private:
		virtual void draw(sf::RenderTarget& target, 
						  sf::RenderStates states) const;
		shotSys::ShotPool* m_pAammo;
		sf::Texture m_texture;
		sf::Sprite m_sprite;
		sf::Color m_color;
		const sf::View* m_pView;
	};
}
#endif // !PLAYER_H
