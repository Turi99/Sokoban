#ifndef WALL_H
#define WALL_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

class Wall : public QGraphicsRectItem {
public:
	Wall(QGraphicsItem *parent = 0);

	QGraphicsRectItem *shape = nullptr;	
};

#endif // !WALL_H
