#ifndef INPUT_H
#define INPUT_H

#include <SFML/Window.hpp>
#include <functional>

namespace input {
	template <typename T>
	class InputObserver {
	public:
		InputObserver(const std::function<bool(T)>& reader, T key);
		void Update();
		bool IsPressed();
		bool PressDown();
		bool PressUp();
	private:
		std::function<bool(T)> m_reader;
		T m_key;
		bool m_currState;
		bool m_prevState;
	};

	template<typename T>
	InputObserver<T>::InputObserver(const std::function<bool(T)>& reader, T key)
		: m_key(key), m_reader(reader),
		m_currState(false), m_prevState(false) {
	}

	template <typename T>
	void InputObserver<T>::Update() {
		m_prevState = m_currState;
		m_currState = m_reader(m_key);
	}

	template <typename T>
	bool InputObserver<T>::IsPressed() {
		return m_currState;
	}

	template <typename T>
	bool InputObserver<T>::PressDown() {
		return (!m_prevState && m_currState);
	}

	template <typename T>
	bool InputObserver<T>::PressUp() {
		return (m_prevState && !m_currState);
	}
}
#endif // !INPUT_H
