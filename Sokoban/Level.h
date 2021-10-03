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
	void resetLevel(int val);

	void changeItemPosition();
	void checkCoinCount();

	int levelNumber = 1;
	int countOfLevel = 4;

	QGraphicsRectItem *levelMap = nullptr;
	Map *map = nullptr;
	Player *player = nullptr;

	//std::vector<std::vector<std::unique_ptr<Box>>> boxs;
	std::vector<std::vector<Box *>> boxs;
	std::vector<Box *> pudelka;
	std::vector<std::pair<int, int>> coordsBoxs;
	//std::vector<Wall *> sciany;
	std::vector<std::pair<int, int>> coordsWalls;
	std::vector<Point *> punkty;
	std::vector<std::pair<int, int>> coordsPoints;
	
	
	//QList<Point *> points;

	//std::vector<std::vector<int>> test;// (t, std::vector<int>(10, 0));

	QGraphicsTextItem *coinCount, *levelText;

	GameMenu *gameMenu = nullptr;

	//void check();

	int ileScian = 0, ilePudelek = 0, ilePunktow = 0;
	void testTworzeniaObiektow();

protected:
	void keyPressEvent(QKeyEvent *event) override;

};


#endif // !LEVEL_H
