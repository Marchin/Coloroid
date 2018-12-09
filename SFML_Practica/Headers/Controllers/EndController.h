#ifndef END_CONTROLLER_H
#define END_CONTROLLER_H

#include "IController.h"

namespace input {

	class EndController : public IController {
	public:
		EndController();
		~EndController();
		virtual void UpdateKeys();
		bool Confirm();
	private:
		typedef InputObserver<sf::Keyboard::Key> Input;
		std::vector<Input*> m_keys;
	};

}
#endif // !GAME_CONTROLLER_H