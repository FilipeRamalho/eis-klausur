#include <QFontDatabase>
#include <PacmanWidget.h>
#include "MenuRenderer.h"

MenuRenderer::MenuRenderer(PacmanWidget *widget) {
	QPainter painter(widget);
	/**
	 * 100px
	 * Pacman [200 px]
	 * 10 px
	 * Title [100px]
	 * 10 px
	 * Classic [20px]
	 * 20 px
	 * Level 1 [20px]
	 * 10 px
	 * Level 2 [20px]
	 * 10 px
	 * Level 3 [20px]
	 * 10 px
	 * Level 3 + PacPill [20px]
	 * 20 px
	 * Tip [20px]
	 * -----
	 */
	QRect r = widget->geometry();
	r.setX(0);
	r.setY(0);
	painter.fillRect(r, QColor(0, 0, 0));

	QFont fixedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
	painter.setPen(Qt::white);

	/** Pacman
	 * Begins at y=100
	 * Height 200px
	 * Ends at y=310
	 */
	QImage pacman = widget->imageLoader.getImage(3);
	pacman = pacman.scaled(200,200);

	//Quelle [4]
	QRect rect(pacman.rect());
	QRect devRect(0, 100, widget->width(), widget->height()-100);
	rect.moveCenter(QPoint(devRect.center().x(),200));
	painter.drawImage(rect.topLeft(), pacman);

	/** Title
	 * Begins at y=310
	 * Height 100px
	 * Ends at y=420
	 */
	QRect rectangle = QRect(0, 310, widget->width(), 100);
	fixedFont.setPixelSize(100);
	painter.setFont(fixedFont);
	painter.drawText(rectangle, Qt::AlignVCenter | Qt::AlignHCenter, "Pacman");

	fixedFont.setPixelSize(20);
	painter.setFont(fixedFont);

	/** Classic 1
	 * Begins at y=420
	 * Height 20px
	 * Ends at y=460
	 */
	rectangle = QRect(0, 420, widget->width(), 20);
	painter.drawText(rectangle, Qt::AlignVCenter | Qt::AlignHCenter, QString("Classic mode: ")+(widget->game->classic_mode ? "on" : "off")+" [Press c]");

	/** Level 1
	 * Begins at y=460
	 * Height 20px
	 * Ends at y=490
	 */
	rectangle = QRect(0, 460, widget->width(), 20);
	painter.drawText(rectangle, Qt::AlignVCenter | Qt::AlignHCenter, "Level 1 [Press 1]");

	/** Level 2
	 * Begins at y=490
	 * Level 1 20px
	 * Ends at y=520
	 */
	rectangle = QRect(0, 490, widget->width(), 20);
	painter.drawText(rectangle, Qt::AlignVCenter | Qt::AlignHCenter, "Level 2 [Press 2]");

	/** Level 3
	 * Begins at y=520
	 * Level 1 20px
	 * Ends at y=560
	 */
	rectangle = QRect(0, 520, widget->width(), 20);
	painter.drawText(rectangle, Qt::AlignVCenter | Qt::AlignHCenter, "Level 3 [Press 3]");

	/** Level 4
	 * Begins at y=550
	 * Level 1 20px
	 * Ends at y=590
	 */
	rectangle = QRect(0, 550, widget->width(), 20);
	painter.drawText(rectangle, Qt::AlignVCenter | Qt::AlignHCenter, "Level 3 + Invincibility pills [Press 4]");

	/** Tip
	 * Begins at y=590
	 * Level 1 20px
	 * Ends at y=630
	 */
	rectangle = QRect(0, 590, widget->width(), 20);
	painter.drawText(rectangle, Qt::AlignVCenter | Qt::AlignHCenter, "You can return to this menu and stop the level with [q]");
}
