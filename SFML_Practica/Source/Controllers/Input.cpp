#include "Controllers/Input.h"

namespace input {
	void Input::Update() {
		m_prevState = m_currState;
		m_currState = sf::Keyboard::isKeyPressed(m_key);
	}

	bool Input::IsPressed() {
		return m_currState;
	}

	bool Input::PressDown() {
		return (!m_prevState && m_currState);
	}

	bool Input::PressUp() {
		return (m_prevState && !m_currState);
	}
}