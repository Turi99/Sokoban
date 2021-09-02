#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include "MainMenu.h"
#include "SelectLevel.h"
#include "Level.h"

class Game : public QGraphicsView {
	Q_OBJECT
public:
	Game(QWidget *parent = 0);

	QGraphicsScene *scene = nullptr;
	MainMenu *mainMenu = nullptr;
	SelectLevel *selectLevel = nullptr;
	Level *level = nullptr;

	void menuToLevel();
	void menuToSelectLvl();
	void selectLvlToMenu();
};

#endif // !GAME_H
