#include "Wall.h"
#include "Game.h"

Wall::Wall(QGraphicsItem *parent): QGraphicsRectItem(parent) {
	//
}

Wall::Wall(QGraphicsItem *parent, int x, int y) : QGraphicsRectItem(parent) {
	shape = new QGraphicsRectItem(this);
	shape->setTransformOriginPoint(0, 0);
	shape->setRect(0, 0, 50, 50);
	shape->setFlag(QGraphicsItem::ItemIsFocusable);
	shape->setFocus();
	shape->setBrush(QPixmap(":/images/Wall.png"));
	shape->setPos(x, y);
}

std::pair<int, int> Wall::getPosition(){
	return std::pair<int, int>(shape->pos().x(), shape->pos().y());
}
