#include <QPainter>
#include <QFontDatabase>
#include <PacmanWidget.h>
#include "EndgameRenderer.h"

EndgameRenderer::EndgameRenderer(PacmanWidget *widget) {
	QPainter painter(widget);
	/**
	 * 100px
	 * -----
	 * 40px
	 * Game Over [100 px]
	 * 10 px
	 * Points [30px]
	 * 10 px
	 * Time [30px]
	 * 10 px
	 * Continue [30px]
	 * 40 px
	 * -----
	 */

	// Black box
	// Total height: 300px
	QRect rectangle = QRect(0, 100, widget->width(), 300);
	painter.fillRect(rectangle, Qt::black);
	painter.setPen(Qt::white);
	painter.drawRect(rectangle);

	// Font
	QFont fixedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
	painter.setPen(Qt::white);

	/** Game Over
	 * Begins at y=140
	 * Height 100px
	 * Ends at y=250
	*/
	rectangle = QRect(0, 140, widget->width(), 100);
	fixedFont.setPixelSize(100);
	painter.setFont(fixedFont);
	if(widget->game->score == widget->game->max_score){
		painter.drawText(rectangle, Qt::AlignVCenter | Qt::AlignHCenter, "Victory!");
	}else{
		painter.drawText(rectangle, Qt::AlignVCenter | Qt::AlignHCenter, "Game Over");
	}

	/** Score
	 * Begins at y=250
	 * Height 30px
	 * Ends at y=290
	 */
	fixedFont.setPixelSize(30);
	painter.setFont(fixedFont);
	rectangle = QRect(0, 250, widget->width(), 30);
	painter.drawText(rectangle, Qt::AlignVCenter | Qt::AlignHCenter, "You got "+QString::number(widget->game->score)+" points out of "+QString::number(widget->game->max_score)+" points");

	/** Score
	 * Begins at y=290
	 * Height 30px
	 * Ends at y=330
	 */
	fixedFont.setPixelSize(30);
	painter.setFont(fixedFont);
	rectangle = QRect(0, 290, widget->width(), 30);
	painter.drawText(rectangle, Qt::AlignVCenter | Qt::AlignHCenter, "Time: "+QString::number(widget->game->time)+" s");

	/** Continue
	 * Begins at y=330
	 * Height 30px
	 * Ends at y=400
	 */
	rectangle = QRect(0, 330, widget->width(), 30);
	painter.drawText(rectangle, Qt::AlignVCenter | Qt::AlignHCenter, "Press [c] to continue");
}
