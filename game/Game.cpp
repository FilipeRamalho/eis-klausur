#include "Game.h"
#include "game/Collision.h"
#include <fstream>
#include <objects/Wall.h>
#include <objects/PacDot.h>
#include <objects/Ghost.h>
#include <objects/SmartGhost.h>
#include <objects/PacPill.h>

uint64_t Game::elapsed_time() const {
	return time;
}

void Game::load(const std::string& file_str){
	std::vector<std::string> lines;

	std::ifstream file(file_str);
	if (file.is_open())	{
		std::string line;
		while (getline(file,line) ){
			lines.push_back(line);
		}
		file.close();
	}

	board.height = static_cast<int>(lines.size());
	board.width = static_cast<int>(lines[0].size());


	for (int i = 0; i < board.width; ++i) {
		for (int j = 0; j < board.height; ++j) {
			auto character = lines[j][i];
			if(character == 'p'){
				pills = true;
			}
		}
	}

	for (int i = 0; i < board.width; ++i) {
		for (int j = 0; j < board.height; ++j) {
			// Alle Heap-Objekte werde in ~Board gelöscht.
			auto character = lines[j][i];
			if(character == '.'){
				board.objects.insert(new PacDot(Position(i,j),&board));
				max_score += 10;
				continue;
			}
			if(character == 'p'){
				board.objects.insert(new PacPill(Position(i,j),&board));
				max_score += 20;
				continue;
			}
			if(character == '-'){
				board.objects.insert(new Wall(Position(i,j),&board,HOR));
				continue;
			}
			if(character == '|'){
				board.objects.insert(new Wall(Position(i,j),&board,VERT));
				continue;
			}
			if(character == 'X'){
				board.objects.insert(new Wall(Position(i,j),&board,BRICK));
				continue;
			}
			if(character == '+'){
				//Right-Up-Corner
				if(lines[j][i-1] == '-' && lines[j+1][i] == '|') {
					board.objects.insert(new Wall(Position(i, j), &board, RU));
					continue;
				}
				//Right-Lower-Corner
				if(lines[j][i-1] == '-' && lines[j-1][i] == '|') {
					board.objects.insert(new Wall(Position(i, j), &board, RL));
					continue;
				}
				//Left-Lower-Corner
				if(lines[j][i+1] == '-' && lines[j-1][i] == '|') {
					board.objects.insert(new Wall(Position(i, j), &board, LL));
					continue;
				}
				//Left-Up-Corner
				if(lines[j][i+1] == '-' && lines[j+1][i] == '|') {
					board.objects.insert(new Wall(Position(i, j), &board, LU));
					continue;
				}
			}
			if(character == 'g'){
				board.objects.insert(new Ghost(Position(i,j),&board));
				continue;
			}
			if(character == 'G'){
				board.objects.insert(new SmartGhost(Position(i,j),&board));
				continue;
			}
			if(character == '*'){
				player = new Player(Position(i,j),&board);
				board.objects.insert(player);
				continue;
			}
		}
	}
	timer.start();
}

void Game::reload(const std::string& file_str) {
	/*
	 * Clearing the game and board
	 */
	for (auto &obj : board.objects) {
		delete obj;
	}
	board.objects.clear();
	delete_pile.clear();
	pills = false;
	score = 0;
	time = 0;
	max_score = 0;
	over = false;

	load(file_str);
}

Game::Game(const std::string& file_str) {
	load(file_str);
}

void Game::act() {
	Collision collision = Collision(&board,player);
	if((collision.check(player->pos,{"Ghost","SmartGhost"}) && player->pill_ticks==0) || max_score == score){
		over = true;
	}

	for (auto &obj : board.objects) {
		obj->act();
	}

	if((collision.check(player->pos,{"Ghost","SmartGhost"}) && player->pill_ticks==0) || max_score == score){
		over = true;
	}

	for (auto &obj : delete_pile) {
		if(dynamic_cast<SmartGhost*>(obj)){
			score += 40;
		} else if(dynamic_cast<Ghost*>(obj)){
			score += 30;
		}else if(dynamic_cast<PacDot*>(obj)){
			score += 10;
		}else if(dynamic_cast<PacPill*>(obj)){
			score += 20;
		}
		board.objects.erase(obj);
		delete obj;
	}
	delete_pile.clear();
}

Game::~Game() {
	for (const auto &item : delete_pile) {
		delete item;
	}
	delete_pile.clear();
}
