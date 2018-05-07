#include "Shot\ShotPool.h"

namespace shot {
	ShotPool::ShotPool(sf::View* pView) {
		m_pView = pView;
		for (int i = 0; i < AMMO_AMOUNT; i++) {
			Shot shot;
			m_shots.push_back(shot);
		}
		m_colors.push_back(sf::Color::Blue);
		m_colors.push_back(sf::Color::Red);
		m_colors.push_back(sf::Color::Green);
		m_colors.push_back(sf::Color::Yellow);
	}

	void ShotPool::RequestShot(sf::Vector2f direction) {
		Shot* shot;
		if (IsShotAvailable(shot)) {
			ResetShotPosition(*shot);
			shot->SetColor(m_colors[rand() % COLORS_AMOUNT]);
			shot->SetDirection(direction);
			shot->Enable();
		}
	}

	void ShotPool::UpdateMovement(const std::vector<sf::Sprite>& obstacles,
		const float deltaTime) {
		for (int i = 0; m_shots.size(); i++) {
			m_shots[i].UpdateMovement(obstacles, deltaTime);
			if (OutOfBound(m_shots[i])) {
				m_shots[i].Disable();
			}
		}
	}

	bool ShotPool::IsShotAvailable(Shot* availableShot) {
		bool isAvailable = false;
		for (int i = 0; m_shots.size(); i++) {
			if (m_shots[i].IsAvailable()) {
				availableShot = &m_shots[i];
				isAvailable = true;
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