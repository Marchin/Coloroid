#ifndef SHOT_POOL_H
#define SHOT_POOL_H

#include "Sprites/ISpritePool.h"
#include "Shot/Shot.h"

namespace shotSys {

class ShotPool : public ISpritePool{
public:
	ShotPool(const sf::View* pView, unsigned int amount);
	unsigned int GetSize() const;
	Shot* operator[](unsigned int index);
	bool Request(const float angle, const sf::Color& color,
		Shot** requested = nullptr);
	void Update(const float deltaTime);
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
private:
	bool IsAvailable(ISprite*& pRequester) override;
	void ResetPosition(ISprite*& shot) override;
	bool OutOfBound(const ISprite* const& shot) const override;
	const sf::View* m_pView;
	std::vector<Shot> m_shots;
};

}

#endif // !SHOT_POOL_H
