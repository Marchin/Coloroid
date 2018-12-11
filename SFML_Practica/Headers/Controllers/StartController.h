#ifndef START_CONTROLLER_H
#define START_CONTROLLER_H

#include "IController.h"
#define UP 0
#define DOWN 1
#define CONFIRM 2

namespace input {

class StartController : public IController {
public:
	StartController();
	~StartController();
	virtual void UpdateKeys();
	bool Up();
	bool Down();
	bool Confirm();
private:
	typedef InputObserver<sf::Keyboard::Key> Input;
	std::vector<Input*> m_keys;
};

}
#endif // !START_CONTROLLER_H