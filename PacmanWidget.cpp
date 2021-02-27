#include "PacmanWidget.h"
#include <QPainter>
#include <QLayout>
#include <QKeyEvent>
#include <functional>
#include <rendering/MenuRenderer.h>
#include <rendering/GameRenderer.h>
#include <rendering/EndgameRenderer.h>

void PacmanWidget::paintEvent(QPaintEvent *event) {

	QPainter painter(this);
	if(mode == GAME || mode == ENDGAME) {
		GameRenderer(this);
	}
	if(mode == ENDGAME){
		EndgameRenderer(this);
	}
	if(mode == MENU) {
		MenuRenderer(this);
	}
	QWidget::paintEvent(event);
}

void PacmanWidget::refreshTimerTimeout() {
	if(!game->over) {
		//Quelle [3]
		game->time = game->timer.elapsed() / 1000;
		game->act();
	}
	if(game->over && mode == GAME)
		mode = ENDGAME;
	update();
}

PacmanWidget::PacmanWidget(Game *game,QWidget *parent ):game(game), QWidget(parent) {
	if(game == nullptr){
		std::cout << ("Woah, no game for me? I need a game to render. -PacmanWidget") << std::endl;
		return;
	}
	imageLoader = ImageLoader();

	resize(63*20,40*20+40);
	setMinimumSize(63*20,40*20+40);
	setMaximumSize(63*20,40*20+40);
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	refreshTimer = new QTimer(this);
	refreshTimer->setInterval(200);
	refreshTimer->setSingleShot(false);
	QObject::connect(refreshTimer, &QTimer::timeout, this, &PacmanWidget::refreshTimerTimeout);
	refreshTimer->start();
}

void PacmanWidget::keyPressEvent(QKeyEvent *event) {
	if(mode == ENDGAME){
		if(event->key() == Qt::Key_C){
			mode = MENU;
		}
		return;
	}else if(mode == MENU){
		//Damit wenn nicht der Classic Mode eingeschaltet wird wenn man
		//ENDGAME zu MENU wechselt.
		if(event->isAutoRepeat()) return;

		if(event->key() == Qt::Key_C) {
			game->classic_mode = !game->classic_mode;
		}
		if(event->key() == Qt::Key_1) {
			game->reload("level1.txt");
			mode = GAME;
		}
		if(event->key() == Qt::Key_2) {
			game->reload("level2.txt");
			mode = GAME;
		}
		if(event->key() == Qt::Key_3) {
			game->reload("level3.txt");
			mode = GAME;
		}
		if(event->key() == Qt::Key_4) {
			game->reload("level4.txt");
			mode = GAME;
		}
		return;
	}else { //mode == GAME
		if(event->key() == Qt::Key_Q)
			mode = MENU;
		if(event->key() == Qt::Key_G)
			game->player->pill_ticks = INT_MAX;
		if (event->key() == Qt::Key_Left)
			game->player->direction = LEFT;
		if (event->key() == Qt::Key_Right)
			game->player->direction = RIGHT;
		if (event->key() == Qt::Key_Down)
			game->player->direction = BOTTOM;
		if (event->key() == Qt::Key_Up)
			game->player->direction = TOP;

		game->pressed = event->key();
		return;
	}
}

void PacmanWidget::keyReleaseEvent(QKeyEvent *event){
	/*
	 * Ich hatte dieses Event mit der ConsoleWindow API verglichen
	 * Anscheinend muss man die losgelassene Taste überprüfen, sonst laggt es
	 * so rum wie in der Musterlösung. (Zu mindestens auf meinen PC)
	 */
	if (event->key() == game->pressed && !game->classic_mode)
		game->player->direction = NONE;
}
