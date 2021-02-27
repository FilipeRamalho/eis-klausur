#ifndef KLAUSUR_ACTOR_H
#define KLAUSUR_ACTOR_H

#include <game/Object.h>
#include <game/Board.h>

struct Actor: Object {
	Direction direction;

	Actor(Position pos, Board* board, Direction direction):Object(pos,board),direction(direction){};

	void move(Direction direction);

};

#endif //KLAUSUR_ACTOR_H
