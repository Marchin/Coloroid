#include "States\GameState.h"
#include "Constants.h"
#include <math.h>

namespace state {
	GameState::GameState(sf::RenderWindow* window, const sf::Time* elapsed)
		: m_pWindow(window), m_time(elapsed) {

		sf::Vector2f screenCenter(window->getView().getSize().x / 2.f, 
			window->getView().getSize().y / 2.f);
		m_pPlayer = new player::Player(screenCenter, &window->getView());
		m_pAsteroids = new asteroidSys::AsteroidPool(&m_pWindow->getView(),
			constant::ASTEROIDS, constant::ASTEROIDS_INTERVAL);
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
			m_pPlayer->Rotate(-constant::TURN_RATE, m_time->asSeconds());
		}
		if (m_gameController.RotateRight()) {
			m_pPlayer->Rotate(constant::TURN_RATE, m_time->asSeconds());
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
		asteroidSys::Asteroid* asteroid;
		if (m_pAsteroids->Request(0.f, sf::Color::Red, &asteroid)) {
			sf::Vector2f direction =
				m_pPlayer->GetPosition() - asteroid->GetPosition();
			asteroid->SetDirection(direction);
		}
		m_pAsteroids->Update(m_time->asSeconds());
	}
}