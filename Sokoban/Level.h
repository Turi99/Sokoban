#ifndef LEVEL_H
#define LEVEL_H

#include <qobject.h>
#include <QGraphicsRectItem>
#include <qgraphicsitem.h>
#include "Map.h"
#include "Player.h"
#include "GameMenu.h"
#include "Box.h"
#include "Point.h"
#include <vector>

class Level: /*public QObject,*/ public QGraphicsRectItem {
	//Q_OBJECT

public:
	Level(QGraphicsItem *parent = 0);
	Level(QGraphicsItem *parent, int nrLevel); // ?? Tworzenie levelu poprzez wybow z "Wybierz poziom"
	void createLevel(int val);
	void nextLevel(int val);

	void changeItemPosition();
	void checkCoinCount();

	int levelNumber = 1;
	int countOfLevel = 4;

	QGraphicsRectItem *levelMap = nullptr;
	Map *map = nullptr;
	Player *player = nullptr;

	//std::vector<std::vector<std::unique_ptr<Box>>> boxs;
	//std::vector<std::vector<Box *>> boxs(10, std::vector<Box *>(10, 0));
	std::vector<std::vector<Box *>> boxs;
	QList<Point *> points;

	QGraphicsTextItem *coinCount;

	GameMenu *gameMenu = nullptr;

	//void check();

protected:
	void keyPressEvent(QKeyEvent *event) override;

};


#endif // !LEVEL_H
