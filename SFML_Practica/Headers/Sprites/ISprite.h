#ifndef ISPRITE_H
#define ISPRITE_H

#include <SFML/Graphics.hpp>

class ISprite : public sf::Drawable {
public:
	virtual ~ISprite() {}
	virtual float GetDirection() const = 0;
	virtual void SetDirection(const float angle) = 0;
	virtual sf::Color GetColor() const = 0;
	virtual void SetColor(const sf::Color& color) = 0;
	virtual bool IsAvailable() const = 0;
	virtual void draw(sf::RenderTarget& target, 
		sf::RenderStates states) const = 0;
	virtual sf::Vector2f GetPosition() const = 0;
	virtual void SetPosition(const sf::Vector2f& position) = 0;
	virtual void Enable() = 0;
	virtual void Disable() = 0;
	virtual float Width() const = 0;
	virtual float Height() const = 0;
};

#endif // !ISPRITE_H
