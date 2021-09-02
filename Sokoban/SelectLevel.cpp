#include "SelectLevel.h"
#include "Game.h"
#include <QKeyEvent>
#include <qmessagebox.h>

extern Game *game;

SelectLevel::SelectLevel(QGraphicsItem *parent) : /*QObject(),*/ QGraphicsRectItem(parent) {
	selectLevelScene = new QGraphicsRectItem(this);
	selectLevelScene->setTransformOriginPoint(0, 0);
	selectLevelScene->setRect(0, 0, 620, 520);
	selectLevelScene->setFlag(QGraphicsItem::ItemIsFocusable);
	selectLevelScene->setFocus();
	selectLevelScene->setBrush(QColor(Qt::green));

	text1 = new QGraphicsTextItem(selectLevelScene);
	text1->setPos(20, 20);
	text1->setPlainText("Select Level");

	arrow = new QGraphicsRectItem(selectLevelScene);
	arrow->setRect(20, 80, 30, 30);
	arrow->setBrush(QColor(Qt::red));

	lvl1 = new QGraphicsTextItem(selectLevelScene);
	lvl1->setPos(80, 82);
	lvl1->setPlainText("Level 1");

	lvl2 = new QGraphicsTextItem(selectLevelScene);
	lvl2->setPos(80, 137);
	lvl2->setPlainText("Level 2");
}

void SelectLevel::setCursorPosition(int val){
	cursorPosition += val;
	if (cursorPosition > 2) {
		cursorPosition = 1;
	}
	else if (cursorPosition < 1) {
		cursorPosition = 2;
	}
	setArrow(cursorPosition);
}

int SelectLevel::getCursorPosition(){
	return cursorPosition;
}

void SelectLevel::keyPressEvent(QKeyEvent *event) {
	/*if(event->key() == Qt::Key_A){
		QMessageBox::information(game, "", "Click key A");
	}*/
	if (event->key() == Qt::Key_Up) {
		setCursorPosition(-1);
	}
	else if (event->key() == Qt::Key_Down) {
		setCursorPosition(1);
	}
	else if (event->key() == Qt::Key_1) {
		//QMessageBox::information(game, "", "Selected level: " + QString::number(cursorPosition));
		//game->createLevel(cursorPosition);
	}
	else if (event->key() == Qt::Key_Escape) {
		game->selectLvlToMenu();
	}
}

void SelectLevel::setArrow(int val){
	arrow->setRect(20, 80 + (55 * (val - 1)), 30, 30);
}
