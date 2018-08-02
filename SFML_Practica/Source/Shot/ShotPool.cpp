#include "Shot/ShotPool.h"

namespace shotSys {
	ShotPool::ShotPool(const sf::View* pView, unsigned int amount) 
		: m_pView(pView) {
	
		m_shots = std::vector<Shot>(amount);
	}

	void ShotPool::RequestShot(const float& angle, 
		const sf::Color& color) {

		Shot* shot = nullptr;
		if (IsShotAvailable(shot)) {
			ResetShotPosition(*shot);
			shot->SetColor(color);
			shot->SetDirection(angle);
			shot->Enable();
		}
	}

	void ShotPool::Update(const std::vector<sf::Sprite>& obstacles,
		const float& deltaTime) {

		for (unsigned int i = 0; i < m_shots.size(); i++) {
			m_shots[i].Update(obstacles, deltaTime);
			if (OutOfBound(m_shots[i])) {
				m_shots[i].Disable();
			}
		}
	}

	void ShotPool::draw(sf::RenderTarget & target,
		sf::RenderStates states) const {
;
		for (Shot shot : m_shots) {
			shot.draw(target, states);
		}
	}

	bool ShotPool::IsShotAvailable(Shot*& pShotRequester) {
		bool isAvailable = false;
		for (unsigned int i = 0; i < m_shots.size(); i++) {
			if (m_shots[i].IsAvailable()) {
				pShotRequester = &m_shots[i];
				isAvailable = true;
				break;
			}
		}
		return isAvailable;
	}

	void ShotPool::ResetShotPosition(Shot& shot) {
		sf::Vector2f screenCenter(
			m_pView->getSize().x / 2.f, m_pView->getSize().y / 2.f);
		shot.SetPosition(screenCenter);
	}

	bool ShotPool::OutOfBound(const Shot& shot) {
		return ((shot.GetPosition().x < 0.f) || 
			(shot.GetPosition().x > m_pView->getSize().x) ||
			(shot.GetPosition().y < 0.f) || 
			(shot.GetPosition().y > m_pView->getSize().y)
			);
	}
}