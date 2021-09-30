#ifndef COIN_H
#define COIN_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

class Coin: public QGraphicsRectItem {
public:
	Coin(QGraphicsItem *parent = 0);

	QGraphicsRectItem *shape = nullptr;
};

#endif // !COIN_H
