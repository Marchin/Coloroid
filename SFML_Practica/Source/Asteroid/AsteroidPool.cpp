#include "Asteroid/AsteroidPool.h"
#include <ctime>

namespace asteroidSys {
	AsteroidPool::AsteroidPool(const sf::View* pView, unsigned int amount) 
		: m_pView(pView) {

		m_asteroids = std::vector<Asteroid>(amount);
	}

	bool AsteroidPool::Request(const float angle, const sf::Color & color) {
		ISprite* asteroid = nullptr;
		if (IsAvailable(asteroid)) {
			ResetPosition(asteroid);
			asteroid->SetColor(color);
			asteroid->SetDirection(angle);
			asteroid->Enable();
			return true;
		} else {
			return false;
		}
	}

	void AsteroidPool::Update(const float deltaTime) {
		for (unsigned int i = 0; i < m_asteroids.size(); i++) {
			m_asteroids[i].Update(deltaTime);
			if (OutOfBound(&m_asteroids[i])) {
				m_asteroids[i].Disable();
			}
		}
	}

	void AsteroidPool::draw(sf::RenderTarget& target, 
		sf::RenderStates states) const {

		for (unsigned int i = 0; i < m_asteroids.size(); i++) {
			m_asteroids[i].draw(target, states);
		}
	}

	unsigned int AsteroidPool::GetSize() const {
		return m_asteroids.size();
	}

	Asteroid AsteroidPool::operator[](unsigned int index) {
		return m_asteroids[index];
	}

	bool AsteroidPool::IsAvailable(ISprite*& pRequester) {
		bool isAvailable = false;
		for (unsigned int i = 0; i < m_asteroids.size(); i++) {
			if (m_asteroids[i].IsAvailable()) {
				pRequester = &m_asteroids[i];
				isAvailable = true;
				break;
			}
		}
		return isAvailable;
	}

	void AsteroidPool::ResetPosition(ISprite*& asteroid) {
		srand(time(0));
		sf::Vector2f newPosition = sf::Vector2f(
			rand()%(int)(m_pView->getSize().x),
			rand()%(int)(m_pView->getSize().y));
		sf::Vector2f axisSelector =
			((rand() % 2) ? sf::Vector2f(0.f, 1.f) : sf::Vector2f(0.f, 1.f));
		newPosition = sf::Vector2f(newPosition.x * axisSelector.x,
			newPosition.y * axisSelector.y);
		asteroid->SetPosition(newPosition);
	}

	bool AsteroidPool::OutOfBound(const ISprite* const& asteroid) const {
		return ((asteroid->GetPosition().x < 0.f) ||
			(asteroid->GetPosition().x > m_pView->getSize().x) ||
			(asteroid->GetPosition().y < 0.f) ||
			(asteroid->GetPosition().y > m_pView->getSize().y)
			);
	}
}