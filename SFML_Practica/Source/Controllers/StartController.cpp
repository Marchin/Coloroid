#include "Controllers\StartController.h"

namespace input {

StartController::StartController(){
	using namespace sf;
	auto reader = &Keyboard::isKeyPressed;
	m_keys.push_back((new Input(reader, Keyboard::Up)));
	m_keys.push_back((new Input(reader, Keyboard::Down)));
	m_keys.push_back((new Input(reader, Keyboard::Space)));
}

StartController::~StartController() {
	for (unsigned int i = 0; i < m_keys.size(); i++) {
		delete m_keys[i];
	}
}

void StartController::UpdateKeys() {
	for (unsigned int i = 0; i < m_keys.size(); i++) {
		m_keys[i]->Update();
	}
}

bool StartController::Up() {
	return m_keys[UP]->PressDown();
}

bool StartController::Down() {
	return m_keys[DOWN]->PressDown();
}

bool StartController::Confirm() {
	return m_keys[CONFIRM]->IsPressed();
}


}