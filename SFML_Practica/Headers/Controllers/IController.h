#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <SFML/Window.hpp>
#include "Input/InputObserver.h"

namespace input {

class IController {
public:
	virtual void UpdateKeys() = 0;
};

}
#endif // !ICONTROLLER_H
