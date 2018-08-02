#include <SFML\Window.hpp>
#include "Input.h"

namespace input {
	class IController {
	public:
		virtual void UpdateKeys() = 0;
	};
}