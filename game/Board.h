#ifndef KLAUSUR_BOARD_H
#define KLAUSUR_BOARD_H

#include <set>
#include <unordered_map>
#include "Position.h"

class Game;
struct Object;

class Board {

public:
	int height;
	int width;
	Game* game;
	std::set<Object*> objects;
	/** If looping through objects is too intensive:
	std::unordered_map<Position,std::vector<Object*>> field;
	**/

	Board(Game* game, int height, int width):game(game),height(height),width(width){}
	~Board();
	Board(const Board&) = delete;
	void operator=(const Board&) = delete;

	std::vector<Object*> get_objects(Position pos);
};


#endif //KLAUSUR_BOARD_H
