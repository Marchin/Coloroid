#include "Shot\ShotPool.h"

namespace shotSys {
	ShotPool::ShotPool(const sf::View* pView) {
		m_pView = pView;
	}

	ShotPool::~ShotPool() {
	}

	std::array<sf::Sprite, AMMO_AMOUNT> ShotPool::GetDrawables() {
		std::array<sf::Sprite, AMMO_AMOUNT> shotSprites;
		for (int i = 0; i < m_shots.size(); i++) {
			shotSprites[i] = m_shots[i].GetDrawable();
		}
		return shotSprites;
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

	void ShotPool::Update(const std::array<sf::Sprite,0>& obstacles,
		const float& deltaTime) {
		for (int i = 0; i < m_shots.size(); i++) {
			m_shots[i].Update(obstacles, deltaTime);
			if (OutOfBound(m_shots[i])) {
				m_shots[i].Disable();
			}
		}
	}

	bool ShotPool::IsShotAvailable(Shot*& shotRequester) {
		bool isAvailable = false;
		for (int i = 0; i < m_shots.size(); i++) {
			if (m_shots[i].IsAvailable()) {
				shotRequester = &m_shots[i];
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