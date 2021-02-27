#include "Board.h"
#include "Object.h"

Board::~Board()  {
	for (const auto &item : objects) {
		delete item;
	}
	objects.clear();
}

std::vector<Object *> Board::get_objects(Position pos) {
	std::vector<Object*> objs;
	/**
	 * WARNING: This has O(n), but multiple objects can request it, so runtime is affected by O(n^2)
	 * Max amount of Objects: 2560 -> Max interaction amount: 6553600 (per Tick)
	 * With current scope, no problem. But for better runtime use unordered Map and hash of Position
	 */
	for (const auto &item : objects) {
		if(item->pos == pos){
			objs.push_back(item);
		}
	}
	return objs;
}
