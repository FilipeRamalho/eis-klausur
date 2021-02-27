#include "SmartGhost.h"
#include <game/Game.h>
#include <game/Collision.h>

void SmartGhost::act() {
	Collision collision = Collision(board,this);

	bool check = collision.check(pos,{"Player"});

	if(check && board->game->player->pill_ticks==0){
		board->game->over = true;
	}else if(check && board->game->player->pill_ticks>0){
		board->game->delete_pile.insert(this);
		return;
	}

	if(moving){
		moving = false;
		return;
	} else {
		moving = true;
		Position old_pos = pos;
		if (board->game->player->pos.x > pos.x) {

			if(board->game->player->pill_ticks == 0)
				move(RIGHT);
			else
				move(LEFT);

			if(!(old_pos == pos))
				return;
		}
		if (board->game->player->pos.x < pos.x) {

			if(board->game->player->pill_ticks == 0)
				move(LEFT);
			else
				move(RIGHT);

			if(!(old_pos == pos))
				return;
		}
		if (board->game->player->pos.y > pos.y) {

			if(board->game->player->pill_ticks == 0)
				move(BOTTOM);
			else
				move(TOP);

			if(!(old_pos == pos))
				return;
		}
		if (board->game->player->pos.y < pos.x) {

			if(board->game->player->pill_ticks == 0)
				move(TOP);
			else
				move(BOTTOM);

			if(!(old_pos == pos))
				return;
		}
	}
}
