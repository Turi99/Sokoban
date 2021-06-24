#include "Game.h"
#include <QKeyEvent>
#include <qpushbutton.h>
#include <qmessagebox.h>

Game::Game(QWidget *parent) :QGraphicsView(parent) {
	QEvent::ApplicationDeactivate; //to jest stare,jak cos

	/*widget = new QWidget();
	widget->setGeometry(0, 0, 600, 500);

	scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, 600, 500);
	scene->setBackgroundBrush(Qt::gray);
	widget->setLayout(scene);*/
	
	scene = new QGraphicsScene(this);
	scene->setSceneRect(0, 0, 600, 500);
	scene->setBackgroundBrush(Qt::gray);
	setScene(scene);
	
	setFixedSize(620, 520);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
	l = new QLabel(this);
	l->setGeometry(530, 10, 70, 25);
	
	l2 = new QLabel(this);
	l2->setGeometry(530, 40, 70, 25);
	
	l4 = new QLabel(this);
	l4->setGeometry(530, 70, 70, 25);

	map = new Map();
	scene->addItem(map);

	player = new Player();
	scene->addItem(player);

}


void Game::resetGame2(QKeyEvent *event) {
	//QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_R, Qt::NoModifier);
	
	if (event->key() == Qt::Key_R) {
		QMessageBox::information(this, "", "Zresetowano poziom");
	}
}

void Game::keyPressEvent(QKeyEvent *event){
	if (event->key() == Qt::Key_R) {
		scene->removeItem(map);
		delete map;
		map = new Map();
		scene->addItem(map);

		scene->removeItem(player);
		delete player;
		player = new Player();
		scene->addItem(player);

		//scene->removeItem(player);
		//player->setPos(50, 50);
		//player->set();
		//scene->addItem(player);
		QMessageBox::information(this, "", "Zresetowano poziom");
	}
	QGraphicsView::keyPressEvent(event);
}
