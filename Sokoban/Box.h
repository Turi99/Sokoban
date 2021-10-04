#ifndef BOX_H
#define BOX_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

class Box: public QGraphicsRectItem {
	QGraphicsRectItem *shape = nullptr;
public:
	Box(QGraphicsItem *parent = 0);
	Box(QGraphicsItem *parent, int x, int y);

	std::pair<int, int> getPosition();
	void setPosition(int x, int y);
};

#endif // !BOX_H
