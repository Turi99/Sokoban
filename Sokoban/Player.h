#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <qobject.h>
#include <qgraphicsitem.h>
#include <qlabel.h>
#include "Box.h"
class Player: /*public QObject,*/ public QGraphicsRectItem{
	//Q_OBJECT
public:
	Player(QGraphicsItem *parent = 0);
	Player(QGraphicsItem *parent, int val);

	QGraphicsRectItem *rectangle;

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	///////
	//void moveRight2(std::vector<std::pair<int, int>> &objectBox);
	void moveLeft2(std::vector<Box *> &pudelka);
	void moveRight2(std::vector<Box *> &pudelka);
	void moveUp2(std::vector<Box *> &pudelka);
	void moveDown2(std::vector<Box *> &pudelka);

private:

};

#endif // !PLAYER_H
