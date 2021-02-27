#include <objects/Player.h>
#include <objects/Wall.h>
#include <objects/PacDot.h>
#include <objects/Ghost.h>
#include <objects/SmartGhost.h>
#include "Collision.h"

bool Collision::check(Position pos) {
	return !board->get_objects(pos).empty();
}

//Use with caution, causes a lot of overhead, as it checks every object on Position for every give type
bool Collision::check(Position pos, const std::vector<std::string>& types) {
	for (auto &type : types) {
		for (auto &object : board->get_objects(pos)) {
			if(type == "Wall"){
				if(dynamic_cast<Wall*>(object)){
					return true;
				}
			}
			if(type == "PacDot"){
				if(dynamic_cast<PacDot*>(object)){
					return true;
				}
			}
			if(type == "SmartGhost"){
				if(dynamic_cast<SmartGhost*>(object)){
					return true;
				}
			}
			if(type == "Ghost"){
				if(dynamic_cast<Ghost*>(object)){
					return true;
				}
			}
			if(type == "Player"){
				if(dynamic_cast<Player*>(object)){
					return true;
				}
			}
		}
	}
	return false;
}

std::vector<Object *> Collision::get(Position pos) {
	return board->get_objects(pos);
}

//Use with caution, causes a lot of overhead, as it checks every object on Position for every give type
std::vector<Object*> Collision::get(Position pos, const std::vector<std::string>& types) {
	std::vector<Object*> result;
	for (auto &type : types) {
		for (auto &object : board->get_objects(pos)) {
			if(type == "Wall"){
				if(dynamic_cast<Wall*>(object)){
					result.push_back(object);
					continue;
				}
			}
			if(type == "PacDot"){
				if(dynamic_cast<PacDot*>(object)){
					result.push_back(object);
					continue;
				}
			}
			if(type == "Ghost"){
				if(dynamic_cast<Ghost*>(object)){
					result.push_back(object);
					continue;
				}
			}
			if(type == "SmartGhost"){
				if(dynamic_cast<Ghost*>(object)){
					result.push_back(object);
					continue;
				}
			}
			if(type == "Player"){
				if(dynamic_cast<Player*>(object)){
					result.push_back(object);
					continue;
				}
			}
		}
	}
	return result;
}
