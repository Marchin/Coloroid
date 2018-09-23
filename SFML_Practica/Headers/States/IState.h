#ifndef ISTATE_H
#define ISTATE_H

#include <SFML\Graphics.hpp>

namespace state {

class IState {
public:
	virtual ~IState() {}
	virtual void Update(IState* nextState, bool& exitGame) = 0;
};

}
#endif // !ISTATE_H