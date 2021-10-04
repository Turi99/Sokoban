#ifndef WALL_H
#define WALL_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

class Wall : public QGraphicsRectItem {
	QGraphicsRectItem *shape = nullptr;	
public:
	Wall(QGraphicsItem *parent = 0);
	Wall(QGraphicsItem *parent, int x, int y);

	std::pair<int, int> getPosition();
};

#endif // !WALL_H
