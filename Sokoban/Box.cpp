#include "Box.h"
#include "Game.h"

//extern Game *game;

Box::Box(QGraphicsItem *parent) : QGraphicsRectItem(parent){
	//shape = new QGraphicsRectItem();
}

Box::Box(QGraphicsItem *parent, int x, int y) : QGraphicsRectItem(parent) {
	shape = new QGraphicsRectItem(this);
	shape->setTransformOriginPoint(0, 0);
	shape->setRect(0, 0, 50, 50);
	shape->setFlag(QGraphicsItem::ItemIsFocusable);
	shape->setFocus();
	shape->setBrush(QPixmap(":/images/brown.png"));
	shape->setBrush(QColor(Qt::green)); // for test
	shape->setPos(x, y);
}

void Box::setTexture(){
	shape->setBrush(QPixmap(":/images/brown.png"));
}
