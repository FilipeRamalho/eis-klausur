#ifndef KLAUSUR_SMARTGHOST_H
#define KLAUSUR_SMARTGHOST_H


#include <objects/Ghost.h>

class SmartGhost : public Ghost{
public:
	bool moving = true;
	SmartGhost(Position pos, Board* board): Ghost(pos,board){};
	void act() override;

};


#endif //KLAUSUR_SMARTGHOST_H
