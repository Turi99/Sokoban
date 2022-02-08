#include "Arrow.h"

Arrow::Arrow(QGraphicsItem *parent) :QGraphicsRectItem(parent) {
	shape = new QGraphicsRectItem(this);
}

void Arrow::setPosition(int x, int y){
	shape->setPos(x, y);
}


