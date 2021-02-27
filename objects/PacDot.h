#ifndef KLAUSUR_PACDOT_H
#define KLAUSUR_PACDOT_H

#include <game/Object.h>

class PacDot : public Object{
public:
	PacDot(Position pos, Board* board): Object(pos,board){};
	void act() override;
};


#endif //KLAUSUR_PACDOT_H
