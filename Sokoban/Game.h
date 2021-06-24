#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <qpushbutton.h>
#include "Player.h"
#include "Map.h"

class Game : public /*QWidget{ //*/QGraphicsView {
	Q_OBJECT
public:
	//explicit Game(QWidget *parent = 0);
	Game(QWidget *parent = 0);
	//Game(QGraphicsScene *scene, QWidget *parent = nullptr);

	//QGraphicsView *view;
	QGraphicsScene *scene;
	Player *player;
	Map *map;

	QLabel *l;
	QLabel *l2;
	QLabel *l4;
	QPushButton *resetButton;
	void resetGame2(QKeyEvent *event);
//protected:
	void keyPressEvent(QKeyEvent *event) override;


};

#endif // !GAME_H
