#ifndef KLAUSUR_GAME_H
#define KLAUSUR_GAME_H

#include <cstdint>
#include <QElapsedTimer>
#include <objects/Player.h>
#include "game/Board.h"

class PacmanWidget;

class Game {
	friend PacmanWidget;
	//Quelle [3]
	QElapsedTimer timer;
	int pressed;
	bool pills = false;

public:
	bool over = false;
	std::set<Object*> delete_pile;
	Player* player;
	uint64_t score = 0;
	bool classic_mode = false;

	explicit Game(const std::string&);
	~Game();
	Game(const Game&) = delete;
	void operator=(const Game&) = delete;

	void act();

	[[nodiscard]] uint64_t elapsed_time() const;

	void reload(const std::string &file_str);

	void load(const std::string &file_str);

	Board board = Board(this, 0, 0);
	uint64_t max_score = 0;
	uint64_t time;
};


#endif //KLAUSUR_GAME_H
