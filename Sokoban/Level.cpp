#include <QKeyEvent>
#include "Level.h"
#include "Game.h"
#include <QMessageBox>
#include <vector>

extern Game *game;

Level::Level(QGraphicsItem *parent): /*QObject(),*/ QGraphicsRectItem(parent) {
	// tworzenie mapy i reszty rzeczy (dla testow)
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
	//testTworzeniaObiektow();
}

void Level::createLevel(int val){
	map = new Map(levelMap, val);
	player = new Player(levelMap, val);

	coinCount = new QGraphicsTextItem(levelMap);
	coinCount->setPos(540, 50);
	coinCount->setPlainText("Coin counts: " + QString::number(map->getCoinCount()));

	levelText = new QGraphicsTextItem(levelMap);
	levelText->setPos(540, 20);
	levelText->setPlainText("Level: " + QString::number(val));
	testTworzeniaObiektow();
}

void Level::nextLevel(int val){
	pudelka.clear();
	coordsBoxs.clear();
	sciany.clear();
	coordsWalls.clear();
	punkty.clear();
	coordsPoints.clear();
	
	delete player;
	delete map;

	delete coinCount;
	delete levelText;

	createLevel(val);
}

void Level::resetLevel(int val){
	pudelka.clear();
	coordsBoxs.clear();
	sciany.clear();
	coordsWalls.clear();
	punkty.clear();
	coordsPoints.clear();
	
	delete player;
	delete map;

	delete coinCount;
	delete levelText;

	createLevel(val);
}

void Level::changeItemPosition(){
	//
}

void Level::checkCoinCount(){
	coinCount->setPlainText("Coin counts: " + QString::number(map->getCoinCount()));

	if (map->getCoinCount() == 0) {
		coinCount->setPlainText("Coin counts: " + QString::number(map->getCoinCount()) + "\n" + "Koniec poziomu");
	}
}

int Level::checkCoinCount(std::vector<Point *> &points, std::vector<Box *> &boxs){
	int countOfSetBox = 0;
	for (int i = 0; i < points.size(); i++) {
		for (int j = 0; j < boxs.size(); j++) {
			if (points[i]->getPosition().first == boxs[j]->getPosition().first && points[i]->getPosition().second == boxs[j]->getPosition().second) {
				countOfSetBox++;
			}
		}
	}
	
	return map->getCoinCount() - countOfSetBox;
}

void Level::checkBoxsAndPoints(std::vector<Point *> &points, std::vector<Box *> &boxs){
	int counts = checkCoinCount(points, boxs);
	coinCount->setPlainText("Coin counts: " + QString::number(counts));

	if (map->getCoinCount() == 0) {
		coinCount->setPlainText("Coin counts: " + QString::number(counts) + "\n" + "Koniec poziomu");
	}
}

////////////////////
#include <qmessagebox.h>
void Level::testTworzeniaObiektow(){
	coordsPoints = map->getCoordsPoint();
	for (int i = 0; i < coordsPoints.size(); i++) {
		punkty.push_back(new Point(levelMap, coordsPoints[i].first, coordsPoints[i].second));
		//punkty.push_back(new Point());
	}
	
	coordsBoxs = map->getCoordsBox();
	for (int i = 0; i < coordsBoxs.size(); i++) {
		//QMessageBox::information(game, "", QString::number(coordsBoxs[i].first) + " " + QString::number(coordsBoxs[i].second));
		pudelka.push_back(new Box(levelMap, coordsBoxs[i].first, coordsBoxs[i].second));
	}


	coordsWalls = map->getCoordsWall();
	for (int i = 0; i < coordsWalls.size(); i++) {
		sciany.push_back(new Wall(levelMap, coordsWalls[i].first, coordsWalls[i].second));
	}
}

/////////////////////////

void Level::keyPressEvent(QKeyEvent *event){
	if (event->key() == Qt::Key_A) {
		if (map->getCoinCount() != 0) {
			//player->moveLeft();
			//player->moveLeft2(pudelka);
			player->moveLeft3(pudelka, sciany);
			//checkCoinCount(punkty,pudelka);
			checkBoxsAndPoints(punkty, pudelka);
			//wyszukajSciany();
		}
	}
	else if (event->key() == Qt::Key_D) {
		if (map->getCoinCount() != 0) {
			//player->moveRight();
			//player->moveRight2(pudelka);
			player->moveRight3(pudelka, sciany);
			//checkCoinCount(punkty, pudelka);
			checkBoxsAndPoints(punkty, pudelka);
		}
	}
	else if (event->key() == Qt::Key_W) {
		if (map->getCoinCount() != 0) {
			//player->moveUp();
			//player->moveUp2(pudelka);
			player->moveUp3(pudelka, sciany);
			//checkCoinCount(punkty, pudelka);
			checkBoxsAndPoints(punkty, pudelka);
		}
	}
	else if (event->key() == Qt::Key_S) {
		if (map->getCoinCount() != 0) {
			//player->moveDown();
			//player->moveDown2(pudelka);
			player->moveDown3(pudelka, sciany);
			//checkCoinCount(punkty, pudelka);
			checkBoxsAndPoints(punkty, pudelka);
		}
	}
	if (event->key() == Qt::Key_Escape) {
		game->levelToMenu();
	}
	if (event->key() == Qt::Key_R) {
		resetLevel(levelNumber);
	}
	if (event->key() == Qt::Key_Space) {
		if (checkCoinCount(punkty,pudelka) == 0) {
			levelNumber++;
			if (levelNumber <= countOfLevel) {
				nextLevel(levelNumber);
			}
		}
	}
}
