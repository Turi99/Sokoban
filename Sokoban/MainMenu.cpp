#include "MainMenu.h"
#include "Game.h"
#include <QKeyEvent>
#include <QMessageBox>

extern Game *game;

MainMenu::MainMenu(QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent) {
	main = new QGraphicsRectItem(this);
	main->setTransformOriginPoint(0, 0);
	main->setRect(0, 0, 620, 520); 
	main->setFlag(QGraphicsItem::ItemIsFocusable);
	main->setFocus();
	main->setBrush(QColor(Qt::green));

	test = new QGraphicsTextItem(main);
	test->setPos(250, 200);
	test->setPlainText("Play");

	test2 = new QGraphicsTextItem(main);
	test2->setPos(250, 260);
	test2->setPlainText("Quit");

	arrow1 = new QGraphicsRectItem(main);
	arrow1->setRect(200, 200, 30, 30);
	arrow1->setBrush(QColor(Qt::red));

	arrow2 = new QGraphicsRectItem(main);
	arrow2->setRect(300, 200, 30, 30);
	arrow2->setBrush(QColor(Qt::red));
}

void MainMenu::setCursorPosition(int val) {
	cursorPosition += val;
	if (cursorPosition > 2) {
		cursorPosition = 1;
	}
	else if (cursorPosition < 1) {
		cursorPosition = 2;
	}
	setArrow(cursorPosition);
}

int MainMenu::getCursorPosition(){
	return cursorPosition;
}

void MainMenu::keyPressEvent(QKeyEvent *event){
	if (event->key() == Qt::Key_Up) {
		setCursorPosition(1);
	}
	else if (event->key() == Qt::Key_Down) {
		setCursorPosition(-1);
	}
	/*else if (event->key() == Qt::Key_Enter) {
		if (cursorPosition == 2) {
			//
		}
	}*/
	//QGraphicsItem::keyPressEvent(event);
}

void MainMenu::setArrow(int val){
	//game->l->setText(QString::number(val));
	//QMessageBox::information(game, "", QString::number(val));
	//test->setPlainText(QString::number(val));
	arrow1->setRect(200, 200+(55*(val-1)), 30, 30);
	arrow2->setRect(300, 200+(55*(val-1)), 30, 30);
}
