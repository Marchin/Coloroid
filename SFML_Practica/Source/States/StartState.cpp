#include "States/StartState.h"
#include "States/GameState.h"
#include "ColorExtension.h"

namespace state {

StartState::StartState(sf::RenderWindow* window, const sf::Time* elapsed) :
	m_pWindow(window), m_pTime(elapsed), m_FLICK_INTERVAL(0.6f), 
	m_counter(m_FLICK_INTERVAL), m_enableControlCounter(1.f),
	m_currentOption(0) {

	if (!m_font.loadFromFile("Resources/8-BIT WONDER.TTF")) {
		printf("Error: Font could not be loaded");
	}
	if (!m_logoTexture.loadFromFile("Resources/Title.png")) {
		printf("Error: failed to load asteroids's texture");
	}
	if (!m_music.openFromFile("Resources/Song.ogg")) {
		printf("Error: failed to load menu's music");
	}

	m_music.setLoop(true);
	m_music.play();

	sf::Vector2f topCenter(window->getView().getSize().x / 2.f, 0.f);

	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.scale(sf::Vector2f(4.f, 4.f));
	m_logoSprite.setOrigin(m_logoSprite.getLocalBounds().width * 0.5f,
		m_logoSprite.getLocalBounds().height * 0.5f);
	topCenter.y += m_logoSprite.getLocalBounds().height * 0.5f + 50.f;
	m_logoSprite.setPosition(topCenter);

	topCenter.y += 80.f;
	m_texts[0].setString("START");
	m_texts[1].setString("EXIT");
	for (int i = 0; i < OPTION_COUNT; i++) 	{
		m_texts[i].setStyle(sf::Text::Bold);
		m_texts[i].setFont(m_font);
		m_texts[i].setCharacterSize(16);
		m_texts[i].setOrigin(m_texts[i].getLocalBounds().width * 0.5f,
			m_texts[i].getLocalBounds().height * 0.5f);
		m_texts[i].setPosition(topCenter);
		topCenter.y += 40.f;
	}
}

StartState::~StartState() {
}

void StartState::Update(IState** pNextState, bool& exitGame){
	if (m_counter <= 0.f) {
		if (m_texts[m_currentOption].getFillColor().a == 0.f) {
			m_texts[m_currentOption].setFillColor(color::Opaque(
				m_texts[m_currentOption].getFillColor()));
		}
		else {
			m_texts[m_currentOption].setFillColor(color::Transparent(
				m_texts[m_currentOption].getFillColor()));
		}
		m_counter = m_FLICK_INTERVAL;
	}
	m_counter -= m_pTime->asSeconds();
	m_pWindow->draw(m_logoSprite);
	for (int i = 0; i < OPTION_COUNT; i++) {
		m_pWindow->draw(m_texts[i]);
	}
	if (m_enableControlCounter < 0.f) {
		CheckInput();
	} else {
		m_enableControlCounter -= m_pTime->asSeconds();
	}
	if (m_startController.Confirm()) {
		m_music.stop();
		if (m_currentOption == 0) {
			*pNextState = new GameState(m_pWindow, m_pTime);
		} else {
			exitGame = true;
		}
	}
}

void StartState::CheckInput() {
	m_startController.UpdateKeys();
	if (m_startController.Up() && m_currentOption > 0) {
		m_texts[m_currentOption].setFillColor(color::Opaque(
			m_texts[m_currentOption].getFillColor()));
		m_currentOption--;
	}
	if (m_startController.Down() && m_currentOption < OPTION_COUNT - 1) {
		m_texts[m_currentOption].setFillColor(color::Opaque(
			m_texts[m_currentOption].getFillColor()));
		m_currentOption++;
	}
}

}