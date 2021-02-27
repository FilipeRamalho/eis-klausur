#include <game/Collision.h>
#include "objects/PacPill.h"
#include <game/Game.h>

void PacPill::act() {
	Collision collision = Collision(board,this);
	if(collision.check(pos,{"Player"})){
		board->game->player->pill_ticks = 10*5; //30 seconds
		board->game->delete_pile.insert(this);
	}
}
