#include "Position.h"

bool Position::operator==(const Position &b) const {
	return (x == b.x) && (y == b.y);
}

void Position::move(Direction direction, uint64_t max_x, uint64_t max_y) {
	if(direction == NONE)
		return;
	if(direction == TOP && y>0){
		y-=1;
		return;
	}
	if(direction == BOTTOM && y<max_y){
		y+=1;
		return;
	}
	if(direction == LEFT && x>0){
		x-=1;
		return;
	}
	if(direction == RIGHT && x<max_x){
		x+=1;
		return;
	}
}

QPoint Position::get_qpoint() const {
	return QPoint(x*20,y*20+40);
}

Direction back(Direction direction) {
	switch (direction) {
		case LEFT: return RIGHT;
		case RIGHT: return LEFT;
		case TOP: return BOTTOM;
		case BOTTOM: return TOP;
	}
	return NONE;
}
