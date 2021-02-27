#ifndef KLAUSUR_GHOST_H
#define KLAUSUR_GHOST_H


#include "Actor.h"

class Ghost : public Actor{
public:
	Ghost(Position pos, Board* board): Actor(pos,board, NONE){};
	void act() override;

};


#endif //KLAUSUR_GHOST_H
