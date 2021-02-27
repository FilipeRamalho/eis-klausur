#include "Actor.h"
#include <game/Collision.h>

void Actor::move(Direction new_direction) {
	Position old_pos = pos;
	pos.move(new_direction,board->width-1,board->height-1);
	if(old_pos == pos){
		return;
	}

	Collision collision = Collision(board,this);
	if(collision.check(pos,{"Wall"})){
		pos.move(back(new_direction),board->width-1,board->height-1);
	}
}
