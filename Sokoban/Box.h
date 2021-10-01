#ifndef BOX_H
#define BOX_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

class Box: public QGraphicsRectItem {
public:
	Box(QGraphicsItem *parent = 0);
	Box(QGraphicsItem *parent, int x, int y);

	QGraphicsRectItem *shape = nullptr;

	void setTexture();
};

#endif // !BOX_H
