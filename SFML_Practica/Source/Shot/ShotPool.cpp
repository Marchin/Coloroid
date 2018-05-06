#include "Shot\Shot.h"
#define AMMO_AMOUNT 3

namespace shot {
	class ShotPool {
	public:
		void RequestShot();
	private:
		std::vector<Shot> shotPool[AMMO_AMOUNT];
		bool IsShotAvailable();
	};
}