#include "Controllers/EndController.h"

namespace input {

EndController::EndController() {
	using namespace sf;
	auto reader = &Keyboard::isKeyPressed;
	m_keys.push_back((new Input(reader, Keyboard::Space)));
	m_keys.push_back((new Input(reader, Keyboard::Return)));
}

EndController::~EndController() {
	for (unsigned int i = 0; i < m_keys.size(); i++) {
		delete m_keys[i];
	}
}

void EndController::UpdateKeys() {
	for (unsigned int i = 0; i < m_keys.size(); i++) {
		m_keys[i]->Update();
	}
}

bool EndController::Confirm() {
	for (unsigned int i = 0; i < m_keys.size(); i++) {
		if (m_keys[i]->IsPressed()) {
			return true;
		}
	}
	return false;
}

}