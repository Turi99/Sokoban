#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <qpushbutton.h>
#include "MainMenu.h"
#include "SelectLevel.h"
#include "Player.h"
#include "Map.h"

class Game : public /*QWidget{ //*/QGraphicsView {
	Q_OBJECT
public:
	//explicit Game(QWidget *parent = 0);
	Game(QWidget *parent = 0);
	//Game(QGraphicsScene *scene, QWidget *parent = nullptr);

	//QGraphicsView *view;
	//QGraphicsView *mainMenu=nullptr;
	QGraphicsScene *scene=nullptr;
	MainMenu *mainMenu = nullptr;
	SelectLevel *selectLevel = nullptr;

	Player *player = nullptr;
	Map *map = nullptr;

	QLabel *l;
	QLabel *l2;
	QLabel *l4;

	QGraphicsTextItem *txt;

	QPushButton *resetButton;
	void resetGame2(QKeyEvent *event);
	void createLevel(int val);

protected:
	void keyPressEvent(QKeyEvent *event) override;


};

#endif // !GAME_H
