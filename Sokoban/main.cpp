#include <QApplication.h>
#include "Game.h"
//#include <qthread.h>

Game *game;

int main(int argc, char *argv[]) {
	//QThread::sleep(15);
	QApplication a(argc, argv);
	//QApplication::focusWidget();

	game = new Game();
	game->show();
	
	return a.exec();
}


//https://youtu.be/lLrhonSCV4s?t=7