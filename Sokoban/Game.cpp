#include "Game.h"
#include <QKeyEvent>
#include <qpushbutton.h>
#include <qmessagebox.h>

Game::Game():QGraphicsView() {
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
	
	//resetButton = new QPushButton(this);
	//resetButton->setGeometry(540, 440, 50, 50);
	//resetButton->setText("Reset");

	//connect(resetButton, SIGNAL(clicked()), this, SLOT(resetGame()));
	//scene->addWidget(resetButton);
	//resetButton->show();
	
	//connect(resetButton, SIGNAL(pressed()), this, SLOT(resetGame2()));
}

void Game::resetGame(){
	QMessageBox::information(this, "", "Zresetowano poziom");
	/*if (map && player) {
		scene->removeItem(map);
		scene->removeItem(player);
		//delete map;
		//delete player;
		map->deleteLater();
		player->deleteLater();
	}

	map = new Map();
	scene->addItem(map);

	player = new Player();
	scene->addItem(player);*/
	
}

void Game::resetGame2() {
	QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_R, Qt::NoModifier);
	if (event->key() == Qt::Key_R) {
		QMessageBox::information(this, "", "Zresetowano poziom");
	}
}