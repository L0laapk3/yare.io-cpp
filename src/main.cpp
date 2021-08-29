
#include "interface.h"
#include "printf.h"



EXPORT("tick")
void tick(int tick, bool initialize) {
	println("cpp is awesome! tick: %i", tick);

	auto myId = Interface::Player::me();

	auto baseX = Interface::Base::positionX(0);
	auto baseY = Interface::Base::positionY(0);
	for (int i = 0; i < Interface::Spirit::count(); i++) {
		if (Interface::Spirit::playerId(i) == myId) {
			Interface::Spirit::shout(i, "cpp 💖");
			Interface::Spirit::move(i, baseX, baseY);
			Interface::Spirit::energizeBase(i, 0);
		}
	}
}