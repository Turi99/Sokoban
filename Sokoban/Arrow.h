#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsRectitem>
#include <QGraphicsItem>

class Arrow : public QGraphicsRectItem {
	QGraphicsRectItem *shape = nullptr;

public:
	Arrow(QGraphicsItem *parent = 0);

	void setPosition(int x, int y);
};

#endif // !ARROW_H
