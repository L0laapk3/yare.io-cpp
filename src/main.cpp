#include <string>


#define IMPORT(module, name) __attribute__((import_module(module), import_name(name)))
#define EXPORT(name) __attribute__((export_name(name)))


IMPORT("players", "me") int myPlayerId();

IMPORT("spirits", "energizeBase") void energizeBase(int, int);
IMPORT("spirits", "move") void move(int, float, float);
IMPORT("spirits", "count") int count();
IMPORT("spirits", "playerId") int playerId(int);
IMPORT("spirits", "shout") void shout(int, const char*);

IMPORT("bases", "positionX") float basePositionX(int);
IMPORT("bases", "positionY") float basePositionY(int);

IMPORT("console", "log") void log(const char*);



EXPORT("tick")
void tick() {
	log("cpp is awesome!");

	auto myId = myPlayerId();

	auto baseX = basePositionX(0);
	auto baseY = basePositionY(0);
	for (int i = 0; i < count(); i++) {
		if (playerId(i) == myId) {
			shout(i, "cpp 💖");
			move(i, baseX, baseY);
			energizeBase(i, 0);
		}
	}
}