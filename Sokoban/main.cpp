#include <QApplication.h>
#include "Game.h"
//#include <qthread.h>

Game *game;

int main(int argc, char *argv[]) {
	//QThread::sleep(15);
	QApplication a(argc, argv);

	game = new Game();
	game->show();
	
	return a.exec();
}