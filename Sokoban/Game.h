#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <qpushbutton.h>
#include "Player.h"
#include "Map.h"

class Game : public QGraphicsView {
public:
	Game();

	QGraphicsScene *scene;
	Player *player;
	Map *map;

	QLabel *l;
	QLabel *l2;
	QLabel *l4;
	QPushButton *resetButton;
public slots:
	void resetGame();
	void resetGame2();
	//void resetGame2(QKeyEvent *event);
};

#endif // !GAME_H
