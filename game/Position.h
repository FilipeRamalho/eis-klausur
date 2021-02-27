

#ifndef KLAUSUR_POSITION_H
#define KLAUSUR_POSITION_H

#include <iostream>
#include <iomanip>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <unordered_set>
#include <qpoint.h>

enum Direction {
	TOP, BOTTOM, LEFT, RIGHT, NONE
};

Direction back(Direction direction);

struct Position {
	int x;
	int y;
	Position(int x,int y):x(x),y(y){};
	bool operator==(const Position&) const;
	void move(Direction direction, uint64_t max_x, uint64_t max_y);
	[[nodiscard]] QPoint get_qpoint() const;
};

#endif //KLAUSUR_POSITION_H
