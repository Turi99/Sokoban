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

	iconLevel = new QGraphicsPixmapItem(selectLevelScene);
	iconLevel->setPos(300, 50);
	iconLevel->setPixmap(QPixmap(":/images/level1.png"));
	iconLevel->setScale(0.5);
	//:/images/level1.png
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
	if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
		setCursorPosition(-1);
	}
	else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
		setCursorPosition(1);
	}
	else if (event->key() == Qt::Key_1) {
		//QMessageBox::information(game, "", "Selected level: " + QString::number(cursorPosition));
		//game->createLevel(cursorPosition);
	}
	else if (event->key() == Qt::Key_Escape) {
		game->selectLvlToMenu();
	}
	else if (event->key() == Qt::Key_Space) {
		game->selectLvlToLevel(cursorPosition);
	}
}

void SelectLevel::setArrow(int val){
	arrow->setRect(20, 80 + (55 * (val - 1)), 30, 30);
	if (val == 1) {
		iconLevel->setPixmap(QPixmap(":/images/level1.png"));
	}
	else if(val == 2){
		//iconLevel->setPixmap(QPixmap());
		iconLevel->setPixmap(QPixmap(":/images/level2.png"));
	}
}
