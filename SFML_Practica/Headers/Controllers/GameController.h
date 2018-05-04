#pragma once
#include "IController.h"
#include <vector>
#define FIRE 0
#define ROTATE_LEFT 1
#define ROTATE_RIGHT 2
#define COLORIZE_BLUE 3
#define COLORIZE_RED 4
#define COLORIZE_GREEN 5
#define COLORIZE_YELLOW 6

namespace controller {
	class GameController :IController {
	public:
		virtual void UpdateKeys();
		GameController();
		bool Fire();
		bool RotateLeft();
		bool RotateRight();
		bool ColorizeBlue();
		bool ColorizeRed();
		bool ColorizeGreen();
		bool ColorizeYellow();
	private:
		std::vector<input::Input> keys;
	};
}