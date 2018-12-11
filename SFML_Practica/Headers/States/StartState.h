#ifndef START_STATE_H
#define START_STATE_H

#include "IState.h"
#include "Controllers/StartController.h"
#include <SFML/Audio.hpp>
#define OPTION_COUNT 2

namespace state {

class StartState : public IState {
public:
	StartState(sf::RenderWindow* window, const sf::Time* elapsed);
	~StartState();
	void Update(IState** pNextState, bool& exitGame) override;
private:
	void CheckInput();
	sf::RenderWindow* m_pWindow;
	const sf::Time* const m_pTime;
	input::StartController m_startController;
	sf::Texture m_logoTexture;
	sf::Sprite m_logoSprite;
	sf::Font m_font;
	sf::Text m_texts[OPTION_COUNT];
	sf::Music m_music;
	int m_currentOption;
	const float m_FLICK_INTERVAL;
	float m_enableControlCounter;
	float m_counter;
};

}

#endif // !START_STATE_H
