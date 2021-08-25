#include <QKeyEvent>
#include "Level.h"
#include "Game.h"

extern Game *game;

Level::Level(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent) {
	// tworzenie mapy i reszty rzeczy
	levelMap = new QGraphicsRectItem(this);
	levelMap->setTransformOriginPoint(0, 0);
	levelMap->setRect(0, 0, 620, 520);
	levelMap->setFlag(QGraphicsItem::ItemIsFocusable);
	levelMap->setFocus();
	levelMap->setBrush(QColor(Qt::gray));
}

void Level::createLevel(int val){
	// tworzenie poziomu
	map = new Map(levelMap);

	player = new Player(levelMap);
}

void Level::keyPressEvent(QKeyEvent *event){
	// klikanie klawiszy 
}
