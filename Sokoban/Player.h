#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <qobject.h>
#include <qgraphicsitem.h>
#include <qlabel.h>
#include "Box.h"
#include "Wall.h"

#include <vector>

struct wyszukajSciany {
	bool operator()(const std::vector<Wall *> &sciany, int posX, int posY) {
		for (int i = 0; i < sciany.size(); i++) {
			if (posX - 50 != sciany[i]->getPosition().first && posY == sciany[i]->getPosition().second) {
				return true;
			}
		}
	}
};

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
	void moveLeft3(std::vector<Box *> &pudelka, std::vector<Wall *> &sciany);
	void moveRight2(std::vector<Box *> &pudelka);
	void moveUp2(std::vector<Box *> &pudelka);
	void moveDown2(std::vector<Box *> &pudelka);

	std::pair<bool, int> wyszukajSciany(std::vector<Wall *> &sciany, int posX, int posY);
	std::pair<bool, int> wyszukajPudelka(std::vector<Box *> &pudelka, int posX, int posY);

private:

};

#endif // !PLAYER_H
