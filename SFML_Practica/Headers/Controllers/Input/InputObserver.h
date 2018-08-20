#ifndef INPUT_H
#define INPUT_H

#include <SFML/Window.hpp>

namespace input {
	template <typename T>
	class InputObserver {
	public:
		InputObserver(bool(*reader)(T key), T key) 
			: m_key(key), m_reader(reader),
			m_currState(false), m_prevState(false) { }

		void Update() {
			m_prevState = m_currState;
			m_currState = m_reader(m_key);
		}

		bool IsPressed() {
			return m_currState;
		}

		bool PressDown() {
			return (!m_prevState && m_currState);
		}

		bool PressUp() {
			return (m_prevState && !m_currState);
		}
	private:
		bool(*m_reader)(T key);
		T m_key;
		bool m_currState;
		bool m_prevState;
	};
}
#endif // !INPUT_H
