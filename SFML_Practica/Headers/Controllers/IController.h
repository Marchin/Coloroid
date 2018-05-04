#pragma once
#include <SFML\Window.hpp>
#include "Input.h"

namespace controller {
	class IController {
	public:
		virtual void UpdateKeys() = 0;
	};
}