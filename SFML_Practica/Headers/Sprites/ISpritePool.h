#ifndef ISPRITE_POOL_H
#define ISPRITE_POOL_H

#include "ISprite.h"

class ISpritePool : public sf::Drawable {
public:
	virtual bool Request(const float angle, const sf::Color& color) = 0;
	virtual void draw(sf::RenderTarget & target,
		sf::RenderStates states) const = 0;
protected:
	virtual bool IsAvailable(ISprite*& pRequester) = 0;
	virtual void ResetPosition(ISprite*& sprite) = 0;
	virtual bool OutOfBound(const ISprite* const& sprite) const = 0;
};

#endif // !ISPRITE_POOL_H
