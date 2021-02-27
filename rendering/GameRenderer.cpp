#include <QFontDatabase>
#include <QPainter>
#include "GameRenderer.h"

GameRenderer::GameRenderer(PacmanWidget *widget) {
	QPainter painter(widget);
	QRect r = widget->geometry();
	r.setX(0);
	r.setY(0);
	painter.fillRect(r, QColor(0, 0, 0));
	QFont fixedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
	fixedFont.setPixelSize(20);
	painter.setFont(fixedFont);
	painter.setPen(Qt::white);
	painter.drawText(QPoint(10, 20), QString("Score: ") + QString::number(widget->game->score));

	QString elapsed_time = QString("Elapsed time: ") + QString::number(widget->game->elapsed_time()) + "s";
	QFontMetrics metrics(fixedFont);
	metrics.width(elapsed_time);
	painter.drawText(QPoint(widget->width()-metrics.width(elapsed_time)-10, 20), elapsed_time);

	for (auto &obj : widget->game->board.objects) {
		painter.drawImage(obj->pos.get_qpoint(), widget->imageLoader.getImage(obj));
	}
}
