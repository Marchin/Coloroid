#pragma once
#include <SFML\Window.hpp>

namespace input {
	class Input {
	public:
		void Update();
		bool IsPressed();
		bool PressDown();
		bool PressUp();
		Input(sf::Keyboard::Key key) : m_key(key),
			m_currState(false), m_prevState(false) {};
	private:
		sf::Keyboard::Key m_key;
		bool m_currState;
		bool m_prevState;
	};
}