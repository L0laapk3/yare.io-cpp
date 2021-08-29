#pragma once

#include "position.h"
#include "shape.h"


#define IMPORT(module, name) __attribute__((import_module(module), import_name(name)))
#define EXPORT(name) __attribute__((export_name(name)))

namespace Interface {
	namespace Spirit {
		IMPORT("spirits", "count") int count();
		IMPORT("spirits", "positionX") float positionX(int);
		IMPORT("spirits", "positionY") float positionY(int);
		// IMPORT("spirits", "position") Position position(int);
		inline Position position(int i) { return Position{ positionX(i), positionY(i) }; }
		IMPORT("spirits", "size") int size(int);
		IMPORT("spirits", "shape") Shape shape(int);
		IMPORT("spirits", "energyCapacity") int energyCapacity(int);
		IMPORT("spirits", "energy") int energy(int);
		IMPORT("spirits", "id") int id(int);
		IMPORT("spirits", "playerId") int playerId(int);
		IMPORT("spirits", "hp") int hp(int);

		IMPORT("spirits", "energize") void energize(int, int);
		IMPORT("spirits", "energizeBase") void energizeBase(int, int);
		IMPORT("spirits", "move") void move(int, float, float);
		IMPORT("spirits", "merge") void merge(int, int);
		IMPORT("spirits", "divide") void divide(int);
		IMPORT("spirits", "jump") void jump(int, float, float);
		IMPORT("spirits", "explode") void explode(int);
		IMPORT("spirits", "shout") void shout(int, const char*);
	};

	namespace Base {
		IMPORT("bases", "count") int count();
		IMPORT("bases", "positionX") float positionX(int);
		IMPORT("bases", "positionY") float positionY(int);
		// IMPORT("bases", "position") Position position(int);
		inline Position position(int i) { return Position{ positionX(i), positionY(i) }; }
		IMPORT("bases", "energyCapacity") int energyCapacity(int);
		IMPORT("bases", "energy") int energy(int);
		IMPORT("bases", "currentSpiritCost") int currentSpiritCost(int);
		IMPORT("bases", "hp") int hp(int);
		IMPORT("bases", "playerId") int playerId(int);
	};

	namespace Star {
		IMPORT("stars", "count") int count();
		IMPORT("stars", "positionX") float positionX(int);
		IMPORT("stars", "positionY") float positionY(int);
		// IMPORT("stars", "position") Position position(int);
		inline Position position(int i) { return Position{ positionX(i), positionY(i) }; }
		IMPORT("stars", "energyCapacity") int energyCapacity(int);
		IMPORT("stars", "energy") int energy(int);
	};

	namespace Outpost {
		IMPORT("outposts", "count") int count();
		IMPORT("outposts", "positionX") float positionX(int);
		IMPORT("outposts", "positionY") float positionY(int);
		// IMPORT("outposts", "position") Position position(int);
		inline Position position(int i) { return Position{ positionX(i), positionY(i) }; }
		IMPORT("outposts", "energyCapacity") int energyCapacity(int);
		IMPORT("outposts", "energy") int energy(int);
		IMPORT("outposts", "range") float range(int);
		IMPORT("outposts", "controlledBy") int controlledBy(int);
	};

	namespace Player {
		IMPORT("players", "count") int count();
		IMPORT("players", "me") int me();
	};

	namespace Console {
		IMPORT("console", "log") void log(const char*);
	};
};
