#include "Point.h"
#include "Game.h"

Point::Point(QGraphicsItem *parent) : QGraphicsRectItem(parent){
	//
}

Point::Point(QGraphicsItem *parent, int x, int y) : QGraphicsRectItem(parent) {
	shape = new QGraphicsRectItem(this);
	shape->setTransformOriginPoint(0, 0);
	shape->setRect(0, 0, 50, 50);
	shape->setFlag(QGraphicsItem::ItemIsFocusable);
	shape->setFocus();
	shape->setBrush(QPixmap("images\\coin.png"));
	shape->setPos(x, y);
}

std::pair<int, int> Point::getPosition(){
	return std::pair<int, int>(shape->pos().x(), shape->pos().y());
}

void Point::setPosition(int x, int y){
	shape->setPos(x, y);
}
