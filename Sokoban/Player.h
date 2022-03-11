#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <qobject.h>
#include <qgraphicsitem.h>
#include <qlabel.h>
#include "Box.h"
#include "Wall.h"

#include <vector>



class Player: /*public QObject,*/ public QGraphicsRectItem{
	//Q_OBJECT
public:
	Player(QGraphicsItem *parent = 0);
	Player(QGraphicsItem *parent, int val);

	QGraphicsRectItem *rectangle;

	void moveLeft3(std::vector<Box *> &pudelka, std::vector<Wall *> &sciany);
	void moveRight3(std::vector<Box *> &pudelka, std::vector<Wall *> &sciany);
	void moveUp3(std::vector<Box *> &pudelka, std::vector<Wall *> &sciany);
	void moveDown3(std::vector<Box *> &pudelka, std::vector<Wall *> &sciany);

	bool wyszukajSciany(std::vector<Wall *> &sciany, int posX, int posY, char c, char d, int distance);
	std::pair<bool,int> wyszukajPudelka(std::vector<Box *> &pudelka, int posX, int posY, char c, char d, int distance);

private:

};

#endif // !PLAYER_H
