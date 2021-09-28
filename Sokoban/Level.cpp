#include <QKeyEvent>
#include "Level.h"
#include "Game.h"
#include <QMessageBox>

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
	levelMap = new QGraphicsRectItem(this);
	levelMap->setTransformOriginPoint(0, 0);
	levelMap->setRect(0, 0, 620, 520);
	levelMap->setFlag(QGraphicsItem::ItemIsFocusable);
	levelMap->setFocus();
	levelMap->setBrush(QColor(Qt::gray));
	createLevel(nrLevel);
}

void Level::createLevel(int val){
	// tworzenie poziomu
	if (val == 1) {
		map = new Map(levelMap);

		player = new Player(levelMap);

		coinCount = new QGraphicsTextItem(levelMap);
		coinCount->setPos(540, 20);
		coinCount->setPlainText("Coin counts: " + QString::number(map->getCoinCount()));

	}
	else if(val == 2) {
		map = new Map(levelMap, 2);

		player = new Player(levelMap);

		coinCount = new QGraphicsTextItem(levelMap);
		coinCount->setPos(540, 20);
		coinCount->setPlainText("Coin counts: " + QString::number(map->getCoinCount()));
	}
	else if (val == 3 || val == 4) {
		map = new Map(levelMap, val);

		player = new Player(levelMap, val);

		coinCount = new QGraphicsTextItem(levelMap);
		coinCount->setPos(540, 20);
		coinCount->setPlainText("Coin counts: " + QString::number(map->getCoinCount()));
	}

	//gameMenu = new GameMenu(levelMap);
	//gameMenu->hide();

}

void Level::keyPressEvent(QKeyEvent *event){
	/*if (event->key() == Qt::Key_Escape) {
		if (gameMenu == nullptr) {
			//gameMenu = new GameMenu();
			//game->scene->addItem(game->gameMenu);
			gameMenu = new GameMenu(levelMap);
		}
		else {
			delete gameMenu;
			gameMenu = nullptr;
		}

		if (!gameMenu->isVisible()) {
			gameMenu->show();
		}
		else {
			gameMenu->hide();
		}

	}*/
	if (event->key() == Qt::Key_A) {
		player->moveLeft();
	}
	else if (event->key() == Qt::Key_D) {
		player->moveRight();
	}
	else if (event->key() == Qt::Key_W) {
		player->moveUp();
	}
	else if (event->key() == Qt::Key_S) {
		player->moveDown();
	}
	if (event->key() == Qt::Key_Escape) {
		game->levelToMenu();
	}

}
