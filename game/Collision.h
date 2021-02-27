#ifndef KLAUSUR_COLLISION_H
#define KLAUSUR_COLLISION_H


#include "Board.h"

class Collision {
	Board* board;
	Object* actor;

public:
	Collision(Board* board, Object* actor):board(board),actor(actor){};

	bool check(Position pos);
	bool check(Position pos, const std::vector<std::string>& types);

	std::vector<Object*> get(Position pos);

	std::vector<Object*> get(Position pos, const std::vector<std::string>& types);
};



#endif //KLAUSUR_COLLISION_H
