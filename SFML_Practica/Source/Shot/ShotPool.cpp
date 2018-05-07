#include "Shot\ShotPool.h"

namespace shotSys {
	ShotPool::ShotPool(const sf::View* pView) {
		m_pView = pView;
		m_colors[0] = sf::Color::Blue;
		m_colors[1] = sf::Color::Red;
		m_colors[2] = sf::Color::Green;
		m_colors[3] = sf::Color::Yellow;
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

	void ShotPool::RequestShot(sf::Vector2f direction) {
		Shot* shot = nullptr;
		if (IsShotAvailable(shot)) {
			ResetShotPosition(*shot);
			shot->SetColor(m_colors[rand() % COLORS_AMOUNT]);
			shot->SetDirection(direction);
			shot->Enable();
		}
	}

	void ShotPool::Update(const std::array<sf::Sprite,0>& obstacles,
		const float deltaTime) {
		for (Shot shot : m_shots) {
			shot.Update(obstacles, deltaTime);
			if (OutOfBound(shot)) {
				shot.Disable();
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