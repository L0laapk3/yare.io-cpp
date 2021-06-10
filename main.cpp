

#define IMPORT(module, name) __attribute__((import_module(module), import_name(name)))
#define EXPORT(name) __attribute__((export_name(name)))


IMPORT("spirits", "energizeBase") void energizeBase(int);
IMPORT("spirits", "move") void move(int, float, float);
IMPORT("spirits", "count") int count();
IMPORT("spirits", "isFriendly") bool isFriendly(int);

IMPORT("bases", "positionX") float basePositionX(int);
IMPORT("bases", "positionY") float basePositionY(int);


EXPORT("tick")
void tick() {
	auto baseX = basePositionX(0);
	auto baseY = basePositionY(0);
	for (int i = 0; i < count(); i++) {
		if (isFriendly(i)) {
			move(i, baseX, baseY);
			energizeBase(i);
		}
	}
}