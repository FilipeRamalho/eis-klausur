#ifndef KLAUSUR_PACMANWIDGET_H
#define KLAUSUR_PACMANWIDGET_H

#include <QWidget>
#include <QTimer>
#include <rendering/ImageLoader.h>
#include "game/Game.h"

enum Mode{
	GAME, MENU, ENDGAME
};

class MenuRenderer;

class PacmanWidget: public QWidget {
	QTimer *refreshTimer;
	Mode mode = MENU;

protected:
	void paintEvent(QPaintEvent *event) override;   protected:
	void keyPressEvent(QKeyEvent *event) override;
	void keyReleaseEvent(QKeyEvent *event) override;

public:
	Game* game;
	explicit PacmanWidget(Game* game, QWidget *parent = nullptr);
	ImageLoader imageLoader;

public slots:
	void refreshTimerTimeout();
};

#endif //KLAUSUR_PACMANWIDGET_H
