#include "PacDot.h"
#include "Player.h"
#include <game/Game.h>
#include <game/Collision.h>

void PacDot::act() {
	Collision collision = Collision(board,this);
	if(collision.check(pos,{"Player"})){
		board->game->delete_pile.insert(this);
	}
}
