#include "GameMenu.h"
#include "Game.h"
#include <QKeyEvent>
#include <qmessagebox.h>

extern Game *game;

GameMenu::GameMenu(QGraphicsItem *parent): QGraphicsRectItem(parent) {
	gameMenu = new QGraphicsRectItem(this);
	gameMenu->setTransformOriginPoint(0, 0);
	gameMenu->setRect(200, 100, 150, 200);
	gameMenu->setFlag(QGraphicsItem::ItemIsFocusable);
	gameMenu->setFocus();
	gameMenu->setBrush(QColor(Qt::red));

}

void GameMenu::keyPressEvent(QKeyEvent *event){
	if (event->key() == Qt::Key_Escape) {
		if (gameMenu) {
			delete this;
			//gameMenu = nullptr;
		}
		//gameMenu = new GameMenu(levelMap);
	}
	else if (event->key() == Qt::Key_1) {
		QMessageBox::information(game, "", "jest");
	}
}
