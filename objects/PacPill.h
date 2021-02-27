#ifndef KLAUSUR_PACPILL_H
#define KLAUSUR_PACPILL_H


#include <objects/PacDot.h>

class PacPill: public PacDot {
public:
	PacPill(Position pos, Board* board): PacDot(pos,board){};
	void act() override;

};


#endif //KLAUSUR_PACPILL_H
