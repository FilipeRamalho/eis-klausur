#include "Player.h"
#include <game/Game.h>
#include <game/Collision.h>

void Player::act() {
	Collision collision = Collision(board,this);

	bool check = collision.check(pos,{"Ghost","SmartGhost"});
	if(check && pill_ticks == 0){
		board->game->over = true;
	}else if(check && pill_ticks>0) {
		for (auto &ghost: collision.get(pos, {"Ghost", "SmartGhost"})) {
			board->game->delete_pile.insert(ghost);
		}
	}
	if(pill_ticks>0){
		pill_ticks -= 1;
	}
	move(direction);
}
