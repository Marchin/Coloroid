#include "States/GameState.h"
#include "Collision/CollisionManager.h"
#include "Constants.h"
#include "ColorExtension.h"
#include <math.h>
#include <sstream>

namespace state {

GameState::GameState(sf::RenderWindow *window, const sf::Time *elapsed)
    : m_pWindow(window), m_time(elapsed) {

	sf::Vector2f screenCenter(window->getView().getSize().x / 2.f,
							window->getView().getSize().y / 2.f);
	m_pPlayer = new player::Player(screenCenter, &window->getView());
	m_pAsteroids = new asteroidSys::AsteroidPool(
		&m_pWindow->getView(), constant::ASTEROIDS, constant::ASTEROIDS_INTERVAL);
	m_pColManager = new Collision::CollisionManager(
		m_pPlayer, m_pPlayer->GetShots(), m_pAsteroids);

	if (!font.loadFromFile("Resources/8-BIT WONDER.TTF")) {
		printf("SHIT");
	}

	text.setCharacterSize(8);

	text.setPosition(sf::Vector2f(5.f, 5.f));

	text.setStyle(sf::Text::Bold);

	text.setFont(font);
	
	if(!m_indicatorImage.loadFromFile("Resources\\Indicator.png")) {
		printf("texture error");
	}
	for (int i = 0; i < 4; i++) {
		sf::Vector2f position(m_pWindow->getView().getSize().x - 12.f * (4 - i), 4.f);
		m_indicators[i].setPosition(position);
		m_indicators[i].setTexture(m_indicatorImage);
		m_indicators[i].setColor(color::ChooseColor(i));
	}
}

GameState::~GameState() {
  delete m_pColManager;
  delete m_pPlayer;
  delete m_pAsteroids;
}

void GameState::Update(IState *pNextState, bool &exitGame) {
	CheckInput();
	UpdateAsteroids();
	m_pPlayer->UpdateShots(m_time->asSeconds());
	m_pWindow->draw(*m_pPlayer);
	m_pWindow->draw(*m_pAsteroids);
	m_pWindow->draw(text);
	for (int i = 0; i < 4; i++) {
		m_pWindow->draw(m_indicators[i]);
	}
	m_pColManager->Update();
	std::ostringstream lifeText;
	lifeText << "Lifes " << m_pPlayer->GetLifes();
	text.setString(lifeText.str());
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
  asteroidSys::Asteroid *asteroid;
  if (m_pAsteroids->Request(0.f, sf::Color::Red, &asteroid)) {
    sf::Vector2f direction = m_pPlayer->GetPosition() - asteroid->GetPosition();
    asteroid->SetDirection(direction);
	asteroid->SetColor(color::ChooseColor(rand() % constant::COLORS_AMOUNT));
  }
  m_pAsteroids->Update(m_time->asSeconds());
}

} // namespace state