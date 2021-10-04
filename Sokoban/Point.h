#ifndef POINT_H
#define POINT_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

class Point: public QGraphicsRectItem {
	QGraphicsRectItem *shape = nullptr;
public:
	Point(QGraphicsItem *parent = 0);
	Point(QGraphicsItem *parent, int x, int y);

	std::pair<int, int> getPosition();
	void setPosition(int x, int y);
};

#endif // !POINT_H
