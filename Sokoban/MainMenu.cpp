#include "MainMenu.h"
#include "Game.h"
#include <QKeyEvent>
#include <QMessageBox>

extern Game *game;

MainMenu::MainMenu(QGraphicsItem *parent) : /*QObject(),*/ QGraphicsRectItem(parent) {
	main = new QGraphicsRectItem(this);
	main->setTransformOriginPoint(0, 0);
	main->setRect(0, 0, 620, 520); 
	main->setFlag(QGraphicsItem::ItemIsFocusable);
	main->setFocus();
	main->setBrush(QColor(Qt::green));

	playTxt = new QGraphicsTextItem(main);	
	playTxt->setPos(250, 200);
	playTxt->setPlainText("Play");

	selectLevelTxt = new QGraphicsTextItem(main);
	selectLevelTxt->setPos(250, 260);
	selectLevelTxt->setPlainText("Select level");

	settingTxt = new QGraphicsTextItem(main);
	settingTxt->setPos(250, 320);
	settingTxt->setPlainText("Settings");

	quitTxt = new QGraphicsTextItem(main);
	quitTxt->setPos(250, 380);
	quitTxt->setPlainText("Quit");

	arrow1 = new QGraphicsRectItem(main);
	arrow1->setRect(200, 200, 30, 30);
	arrow1->setBrush(QColor(Qt::red));

	arrow2 = new QGraphicsRectItem(main);
	arrow2->setRect(350, 200, 30, 30);
	arrow2->setBrush(QColor(Qt::red));
}

void MainMenu::setCursorPosition(int val) {
	cursorPosition += val;
	if (cursorPosition > 4) {
		cursorPosition = 1;
	}
	else if (cursorPosition < 1) {
		cursorPosition = 4;
	}
	setArrow(cursorPosition);
}

int MainMenu::getCursorPosition(){
	return cursorPosition;
}

void MainMenu::keyPressEvent(QKeyEvent *event){
	if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
		setCursorPosition(-1);
	}
	else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
		setCursorPosition(1);
	}
	else if (event->key() == Qt::Key_Escape) {
		exit(EXIT_SUCCESS);
	}
	else if (event->key() == Qt::Key_Space) {
		if (cursorPosition == 1) {
			game->menuToLevel();
		}
		else if (cursorPosition == 2) {
			game->menuToSelectLvl();
		}
		else if (cursorPosition == 3) {
			game->settingsToMenu();
		}
		else if(cursorPosition == 4){
			exit(EXIT_SUCCESS);
		}
	}
}

void MainMenu::setArrow(int val){
	arrow1->setRect(200, 200+(55*(val-1)), 30, 30);
	arrow2->setRect(350, 200+(55*(val-1)), 30, 30);
}
