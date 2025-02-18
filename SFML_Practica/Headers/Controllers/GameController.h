#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "IController.h"
#define FIRE 0
#define ROTATE_LEFT 1
#define ROTATE_RIGHT 2
#define COLORIZE_BLUE 3
#define COLORIZE_RED 4
#define COLORIZE_GREEN 5
#define COLORIZE_YELLOW 6

namespace input {

class GameController : public IController {
public:
	GameController();
	~GameController();
	virtual void UpdateKeys();
	bool Fire();
	bool RotateLeft();
	bool RotateRight();
	bool ColorizeBlue();
	bool ColorizeRed();
	bool ColorizeGreen();
	bool ColorizeYellow();
private:
	typedef InputObserver<sf::Keyboard::Key> Input;
	std::vector<Input*> m_keys;
};

}
#endif // !GAME_CONTROLLER_H