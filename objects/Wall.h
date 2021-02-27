#ifndef KLAUSUR_WALL_H
#define KLAUSUR_WALL_H

#include <game/Object.h>
#include <utility>

enum Type{
	HOR,VERT,BRICK,LL,LU,RL,RU
};

class Wall : public Object{
public:
	Type type;
	Wall(Position pos, Board* board, Type type): Object(pos,board), type(type){};
	void act() override;
};

#endif //KLAUSUR_WALL_H
