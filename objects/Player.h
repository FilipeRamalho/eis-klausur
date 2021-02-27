#ifndef KLAUSUR_PLAYER_H
#define KLAUSUR_PLAYER_H


#include "Actor.h"

class Player: public Actor {

public:
	Player(Position pos, Board* board): Actor(pos,board, NONE){};
	void act() override;
	int pill_ticks = 0;
};


#endif //KLAUSUR_PLAYER_H
