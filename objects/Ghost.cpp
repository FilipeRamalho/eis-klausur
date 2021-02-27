#include "Ghost.h"
#include <random>
#include <game/Collision.h>
#include <game/Game.h>

void Ghost::act() {
	Collision collision = Collision(board,this);

	bool check = collision.check(pos,{"Player"});

	if(check && board->game->player->pill_ticks==0){
		board->game->over = true;
	}else if(check && board->game->player->pill_ticks>0){
		board->game->delete_pile.insert(this);
		return;
	}

	std::vector<Direction> free_directions = {};
	Position old_pos = pos;

	move(BOTTOM);
	if(!(old_pos == pos)) {
		free_directions.push_back(BOTTOM);
		move(back(BOTTOM));
	}
	move(TOP);
	if(!(old_pos == pos)){
		free_directions.push_back(TOP);
		move(back(TOP));
	}
	move(LEFT);
	if(!(old_pos == pos)){
		free_directions.push_back(LEFT);
		move(back(LEFT));
	}
	move(RIGHT);
	if(!(old_pos == pos)){
		free_directions.push_back(RIGHT);
		move(back(RIGHT));
	}

	// Quelle [1]
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<unsigned long long> uni(0, free_directions.size()-1);
	auto rand = uni(rng);
	move(free_directions[rand]);
}
