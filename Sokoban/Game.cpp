#include "Game.h"
#include <QKeyEvent>
#include <qmessagebox.h>


Game::Game(QWidget *parent) : QGraphicsView(parent) {
	QEvent::ApplicationActivate; //to jest stary sposob

	scene = new QGraphicsScene(this);
	scene->setSceneRect(0, 0, 620, 520);
	setScene(scene);

	setFixedSize(620, 520);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	mainMenu = new MainMenu();
	scene->addItem(mainMenu);

}

void Game::menuToLevel() {
	delete mainMenu;
	mainMenu = nullptr;
	level = new Level(0,1);
	scene->addItem(level);
}

void Game::menuToSelectLvl() {
	delete mainMenu;
	mainMenu = nullptr;
	selectLevel = new SelectLevel();
	scene->addItem(selectLevel);
}

void Game::selectLvlToMenu() {
	delete selectLevel;
	selectLevel = nullptr;
	mainMenu = new MainMenu();
	scene->addItem(mainMenu);
}

void Game::selectLvlToLevel(int val) {
	delete selectLevel;
	selectLevel = nullptr;
	level = new Level(0,val);
	scene->addItem(level);
}

void Game::levelToMenu(){
	delete level;
	level = nullptr;
	mainMenu = new MainMenu();
	scene->addItem(mainMenu);
}

void Game::menuToSettings(){
	//
}

void Game::settingsToMenu(){
	//
}
