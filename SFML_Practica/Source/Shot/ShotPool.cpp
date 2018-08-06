#include "Shot/ShotPool.h"

namespace shotSys {
	ShotPool::ShotPool(const sf::View* pView, unsigned int amount) 
		: m_pView(pView) {
	
		m_shots = std::vector<Shot>(amount);
	}

	bool ShotPool::Request(const float angle, 
		const sf::Color& color) {

		ISprite* shot = nullptr;
		if (IsAvailable(shot)) {
			ResetPosition(shot);
			shot->SetColor(color);
			shot->SetDirection(angle);
			shot->Enable();
			return true;
		} else {
			return false;
		}
	}

	void ShotPool::Update(const float deltaTime,
		const std::vector<sf::Sprite>& obstacles) {

		for (unsigned int i = 0; i < m_shots.size(); i++) {
			m_shots[i].Update(obstacles, deltaTime);
			if (OutOfBound(&m_shots[i])) {
				m_shots[i].Disable();
			}
		}
	}

	void ShotPool::draw(sf::RenderTarget& target,
		sf::RenderStates states) const {
;
		for (Shot shot : m_shots) {
			shot.draw(target, states);
		}
	}

	bool ShotPool::IsAvailable(ISprite*& pRequester){
		bool isAvailable = false;
		for (unsigned int i = 0; i < m_shots.size(); i++) {
			if (m_shots[i].IsAvailable()) {
				pRequester = &m_shots[i];
				isAvailable = true;
				break;
			}
		}
		return isAvailable;
	}

	void ShotPool::ResetPosition(ISprite*& shot) {
		sf::Vector2f screenCenter(
			m_pView->getSize().x / 2.f, m_pView->getSize().y / 2.f);
		shot->SetPosition(screenCenter);
	}

	bool ShotPool::OutOfBound(const ISprite* const& shot) const{
		return ((shot->GetPosition().x < 0.f) || 
			(shot->GetPosition().x > m_pView->getSize().x) ||
			(shot->GetPosition().y < 0.f) || 
			(shot->GetPosition().y > m_pView->getSize().y)
			);
	}
}