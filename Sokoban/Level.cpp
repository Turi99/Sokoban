#include <QKeyEvent>
#include "Level.h"
#include "Game.h"

extern Game *game;

Level::Level(QGraphicsItem *parent): /*QObject(),*/ QGraphicsRectItem(parent) {
	// tworzenie mapy i reszty rzeczy
	levelMap = new QGraphicsRectItem(this);
	levelMap->setTransformOriginPoint(0, 0);
	levelMap->setRect(0, 0, 620, 520);
	levelMap->setFlag(QGraphicsItem::ItemIsFocusable);
	levelMap->setFocus();
	levelMap->setBrush(QColor(Qt::gray));
	createLevel(1);

}

Level::Level(QGraphicsItem *parent, int nrLevel) : QGraphicsRectItem(parent), levelNumber(nrLevel) {
	//
}

void Level::createLevel(int val){
	// tworzenie poziomu
	map = new Map(levelMap);

	player = new Player(levelMap);

	coinCount = new QGraphicsTextItem(levelMap);
	coinCount->setPos(540, 20);
	coinCount->setPlainText("Coin counts: " + QString::number(map->getCoinCount()));
}

void Level::keyPressEvent(QKeyEvent *event){
	if (event->key() == Qt::Key_Escape) {
		//exit(EXIT_SUCCESS);
	}
}
