#include "PacmanWidget.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char* argv[]) {

	Game give_me_a_name("level1.txt");
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication app(argc,argv);

	PacmanWidget pacman = PacmanWidget(&give_me_a_name);

	pacman.setWindowIcon(QIcon(QPixmap("pacman.png")));
	pacman.show();

	return QApplication::exec();
}