#include <SFML\Graphics.hpp>

namespace state {
	class IState {
	public:
		virtual void Update(IState* nextState) = 0;
	protected:
		virtual void StateLoop() = 0;
	};
}