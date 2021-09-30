#ifndef BOX_H
#define BOX_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

class Box: public QGraphicsRectItem {
public:
	Box(QGraphicsItem *parent = 0);

	QGraphicsRectItem *shape = nullptr;
};

#endif // !BOX_H
