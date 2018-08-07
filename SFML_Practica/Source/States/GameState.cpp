#include "States\GameState.h"
#include "Constants.h"
#include <math.h>

namespace state {
	GameState::GameState(sf::RenderWindow* window, const sf::Time* elapsed)
		: m_pWindow(window), m_time(elapsed) {

		sf::Vector2f screenCenter(window->getView().getSize().x / 2.f, 
			window->getView().getSize().y / 2.f);
		m_pPlayer = new player::Player(screenCenter, &window->getView());
		m_pAsteroids = new asteroidSys::AsteroidPool(
			&m_pWindow->getView(), constant::ASTEROIDS);
	}

	GameState::~GameState() {
		delete m_pPlayer;
		delete m_pAsteroids;
	}

	void GameState::Update(IState* pNextState, bool& exitGame) {
		CheckInput();
		UpdateAsteroids();
		m_pPlayer->UpdateShots(*m_pAsteroids, m_time->asSeconds());
		m_pWindow->draw(*m_pPlayer);
		m_pWindow->draw(*m_pAsteroids);
		pNextState = this;
	}

	void GameState::CheckInput() {
		m_gameController.UpdateKeys();
		if (m_gameController.RotateLeft()) {
			m_pPlayer->Rotate(-90.f, m_time->asSeconds());
		}
		if (m_gameController.RotateRight()) {
			m_pPlayer->Rotate(90.f, m_time->asSeconds());
		}
		if (m_gameController.Fire()) {
			m_pPlayer->Fire();
		}
		if (m_gameController.ColorizeBlue()) {
			m_pPlayer->SetColor(sf::Color::Blue);
		}
		if (m_gameController.ColorizeRed()) {
			m_pPlayer->SetColor(sf::Color::Red);
		}
		if (m_gameController.ColorizeGreen()) {
			m_pPlayer->SetColor(sf::Color::Green);
		}
		if (m_gameController.ColorizeYellow()) {
			m_pPlayer->SetColor(sf::Color::Yellow);
		}
	}

	void GameState::UpdateAsteroids() {
		for (unsigned int i = 0; i < m_pAsteroids->GetSize(); i++) {
			if (m_pAsteroids->Request(0, sf::Color::Red)) {
				sf::Vector2f direction =
					m_pPlayer->GetPosition() - m_pAsteroids->operator[](i).GetPosition();
				float angle = atan((direction.y / direction.x) * 180 / constant::PI);
				m_pAsteroids->operator[](i).SetDirection(angle);
				break;
			}
		}
		m_pAsteroids->Update(m_time->asMilliseconds());
	}
}