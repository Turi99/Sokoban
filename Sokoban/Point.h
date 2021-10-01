#ifndef POINT_H
#define POINT_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

class Point: public QGraphicsRectItem {
public:
	Point(QGraphicsItem *parent = 0);

	QGraphicsRectItem *shape = nullptr;
};

#endif // !POINT_H
