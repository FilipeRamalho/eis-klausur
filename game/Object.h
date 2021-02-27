#ifndef KLAUSUR_OBJECT_H
#define KLAUSUR_OBJECT_H

#include "Position.h"

class Board;

struct Object {
	Position pos;
	Board* board;

	Object(Position pos, Board* board): pos(pos), board(board){};

	virtual void act() = 0;
	virtual ~Object() = default;
};


#endif //KLAUSUR_OBJECT_H
