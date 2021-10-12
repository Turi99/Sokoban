#include "Player.h"
#include <QGraphicsRectItem>
//#include <QKeyEvent>
#include "Game.h"
#include "Map.h"
#include "Level.h"
#include "qmessagebox.h"

extern Game *game;

Player::Player(QGraphicsItem *parent) :/*QObject(),*/ QGraphicsRectItem(parent) {
	rectangle = new QGraphicsRectItem(this);
	rectangle->setTransformOriginPoint(0, 0);
	//rectangle->setRect(0, 0, 40, 40);
	rectangle->setRect(0, 0, 50, 50);
	rectangle->setFlag(QGraphicsItem::ItemIsFocusable);
	rectangle->setFocus();
	//rectangle->setBrush(QColor(Qt::green));
	rectangle->setBrush(QPixmap(":/images/gif1.gif"));
	//rectangle->setPos(5, 5);
	setPos(50, 50);
}

Player::Player(QGraphicsItem *parent, int val) :/*QObject(),*/ QGraphicsRectItem(parent) {
	rectangle = new QGraphicsRectItem(this);
	rectangle->setTransformOriginPoint(0, 0);
	//rectangle->setRect(0, 0, 40, 40);
	rectangle->setRect(0, 0, 50, 50);
	rectangle->setFlag(QGraphicsItem::ItemIsFocusable);
	rectangle->setFocus();
	//rectangle->setBrush(QColor(Qt::green));
	rectangle->setBrush(QPixmap(":/images/PlayerRight.png"));
	//rectangle->setPos(5, 5);
	if (val == 1 || val == 2) {
		setPos(50, 50);
	}
	else if(val == 3){
		setPos(300, 200);
	}
	else if (val == 4) {
		setPos(100, 100);
	}
}

void Player::moveLeft() {
	int posX = pos().x();
	int posY = pos().y();

	if (game->level->map->mapa[posY / 50 - 0][posX / 50 - 1] == 3) {
		if (game->level->map->mapa[posY / 50 - 0][posX / 50 - 2] != 1 && game->level->map->mapa[posY / 50 - 0][posX / 50 - 2] != 3) {
			setPos(x() - 50, y());
			posX = pos().x();
			posY = pos().y();
			game->level->map->mapka[posX / 50 - 1][posY / 50 - 0]->setBrush(QPixmap(":/images/brown.png"));
			game->level->map->mapa[posY / 50 - 0][posX / 50 - 1] = 3;
			game->level->map->mapka[posX / 50][posY / 50]->setBrush(QPixmap(":/images/white.png"));
			game->level->map->mapa[posY / 50][posX / 50] = 0;
		}
	}
	else if (game->level->map->mapa[posY / 50 - 0][posX / 50 - 1] != 1) {
		setPos(x() - 50, y());
	}

	rectangle->setBrush(QPixmap(":/images/PlayerLeft.png"));
}

void Player::moveRight(){
	int posX = pos().x();
	int posY = pos().y();

	if (game->level->map->mapa[posY / 50 - 0][posX / 50 + 1] == 3) {
		if (game->level->map->mapa[posY / 50 - 0][posX / 50 + 2] != 1 && game->level->map->mapa[posY / 50 - 0][posX / 50 + 2] != 3) {
			setPos(x() + 50, y());
			posX = pos().x();
			posY = pos().y();
			game->level->map->mapka[posX / 50 + 1][posY / 50 - 0]->setBrush(QPixmap(":/images/brown.png"));
			game->level->map->mapa[posY / 50 - 0][posX / 50 + 1] = 3;
			game->level->map->mapka[posX / 50][posY / 50]->setBrush(QPixmap(":/images/white.png"));
			game->level->map->mapa[posY / 50][posX / 50] = 0;
		}
	}
	else if (game->level->map->mapa[posY / 50 - 0][posX / 50 + 1] != 1) {
		setPos(x() + 50, y());
	}

	rectangle->setBrush(QPixmap(":/images/PlayerRight.png"));
}

void Player::moveUp(){
	int posX = pos().x();
	int posY = pos().y();

	if (game->level->map->mapa[posY / 50 - 1][posX / 50 + 0] == 3) {
		if (game->level->map->mapa[posY / 50 - 2][posX / 50 + 0] != 1 && game->level->map->mapa[posY / 50 - 2][posX / 50 - 0] != 3) {
			setPos(x(), y() - 50);
			posX = pos().x();
			posY = pos().y();
			game->level->map->mapka[posX / 50 + 0][posY / 50 - 1]->setBrush(QPixmap(":/images/brown.png"));
			game->level->map->mapa[posY / 50 - 1][posX / 50 + 0] = 3;
			game->level->map->mapka[posX / 50][posY / 50]->setBrush(QPixmap(":/images/white.png"));
			game->level->map->mapa[posY / 50][posX / 50] = 0;
		}
	}
	else if (game->level->map->mapa[posY / 50 - 1][posX / 50 + 0] != 1) {
		setPos(x(), y() - 50);
	}

	rectangle->setBrush(QPixmap(":/images/PlayerUp.png"));
}

void Player::moveDown(){
	int posX = pos().x();
	int posY = pos().y();

	if (game->level->map->mapa[posY / 50 + 1][posX / 50 + 0] == 3) {
		if (game->level->map->mapa[posY / 50 + 2][posX / 50 + 0] != 1 && game->level->map->mapa[posY / 50 + 2][posX / 50 - 0] != 3) {
			setPos(x(), y() + 50);
			posX = pos().x();
			posY = pos().y();
			game->level->map->mapka[posX / 50 + 0][posY / 50 + 1]->setBrush(QPixmap(":/images/brown.png"));
			game->level->map->mapa[posY / 50 + 1][posX / 50 + 0] = 3;
			game->level->map->mapka[posX / 50][posY / 50]->setBrush(QPixmap(":/images/white.png"));
			game->level->map->mapa[posY / 50][posX / 50] = 0;
		}
	}
	else if (game->level->map->mapa[posY / 50 + 1][posX / 50 + 0] != 1) {
		setPos(x(), y() + 50);
	}

	rectangle->setBrush(QPixmap(":/images/PlayerDown.png"));
}



///////////////


void Player::moveLeft2(std::vector<Box *> &pudelka){
	int posX = pos().x();
	int posY = pos().y();

	for (int i = 0; i < pudelka.size(); i++) {
		if (posX - 50 == pudelka[i]->getPosition().first && posY == pudelka[i]->getPosition().second) {
			pudelka[i]->setPosition(pudelka[i]->getPosition().first - 50, pudelka[i]->getPosition().second);
		}
	}

	if (game->level->map->mapa[posY / 50 - 0][posX / 50 - 1] == 3) {
		if (game->level->map->mapa[posY / 50 - 0][posX / 50 - 2] != 1 && game->level->map->mapa[posY / 50 - 0][posX / 50 - 2] != 3) {
			setPos(x() - 50, y());
			//posX = pos().x();
			//posY = pos().y();
			//game->level->map->mapka[posX / 50 - 1][posY / 50 - 0]->setBrush(QPixmap(":/images/brown.png"));
			//game->level->map->mapa[posY / 50 - 0][posX / 50 - 1] = 3;
			//game->level->map->mapka[posX / 50][posY / 50]->setBrush(QPixmap(":/images/white.png"));
			//game->level->map->mapa[posY / 50][posX / 50] = 0;
		}
	}
	else if (game->level->map->mapa[posY / 50 - 0][posX / 50 - 1] != 1) {
		setPos(x() - 50, y());
	}

	rectangle->setBrush(QPixmap(":/images/PlayerLeft.png"));
}

void Player::moveRight2(std::vector<Box *> &pudelka) {
	int posX = pos().x();
	int posY = pos().y();

	for (int i = 0; i < pudelka.size(); i++) {
		if (posX+50 == pudelka[i]->getPosition().first && posY==pudelka[i]->getPosition().second) {
			pudelka[i]->setPosition(pudelka[i]->getPosition().first + 50, pudelka[i]->getPosition().second);
		}
	}

	if (game->level->map->mapa[posY / 50 - 0][posX / 50 + 1] == 3) {
		if (game->level->map->mapa[posY / 50 - 0][posX / 50 + 2] != 1 && game->level->map->mapa[posY / 50 - 0][posX / 50 + 2] != 3) {
			setPos(x() + 50, y());
			//posX = pos().x();
			//posY = pos().y();
			//game->level->map->mapka[posX / 50 + 1][posY / 50 - 0]->setBrush(QPixmap(":/images/brown.png"));
			//game->level->map->mapa[posY / 50 - 0][posX / 50 + 1] = 3;
			//game->level->map->mapka[posX / 50][posY / 50]->setBrush(QPixmap(":/images/white.png"));
			//game->level->map->mapa[posY / 50][posX / 50] = 0;
		}
	}
	else if (game->level->map->mapa[posY / 50 - 0][posX / 50 + 1] != 1) {
		setPos(x() + 50, y());
	}

	rectangle->setBrush(QPixmap(":/images/PlayerRight.png"));
}

void Player::moveUp2(std::vector<Box *> &pudelka){
	int posX = pos().x();
	int posY = pos().y();

	for (int i = 0; i < pudelka.size(); i++) {
		if (posX == pudelka[i]->getPosition().first && posY - 50 == pudelka[i]->getPosition().second) {
			pudelka[i]->setPosition(pudelka[i]->getPosition().first, pudelka[i]->getPosition().second - 50);
		}
	}

	if (game->level->map->mapa[posY / 50 - 1][posX / 50 + 0] == 3) {
		if (game->level->map->mapa[posY / 50 - 2][posX / 50 + 0] != 1 && game->level->map->mapa[posY / 50 - 2][posX / 50 - 0] != 3) {
			setPos(x(), y() - 50);
			//posX = pos().x();
			//posY = pos().y();
			//game->level->map->mapka[posX / 50 + 0][posY / 50 - 1]->setBrush(QPixmap(":/images/brown.png"));
			//game->level->map->mapa[posY / 50 - 1][posX / 50 + 0] = 3;
			//game->level->map->mapka[posX / 50][posY / 50]->setBrush(QPixmap(":/images/white.png"));
			//game->level->map->mapa[posY / 50][posX / 50] = 0;
		}
	}
	else if (game->level->map->mapa[posY / 50 - 1][posX / 50 + 0] != 1) {
		setPos(x(), y() - 50);
	}

	rectangle->setBrush(QPixmap(":/images/PlayerUp.png"));
}

void Player::moveDown2(std::vector<Box *> &pudelka){
	int posX = pos().x();
	int posY = pos().y();

	for (int i = 0; i < pudelka.size(); i++) {
		if (posX == pudelka[i]->getPosition().first && posY + 50 == pudelka[i]->getPosition().second) {
			pudelka[i]->setPosition(pudelka[i]->getPosition().first, pudelka[i]->getPosition().second + 50);
		}
	}

	if (game->level->map->mapa[posY / 50 + 1][posX / 50 + 0] == 3) {
		if (game->level->map->mapa[posY / 50 + 2][posX / 50 + 0] != 1 && game->level->map->mapa[posY / 50 + 2][posX / 50 - 0] != 3) {
			setPos(x(), y() + 50);
			//posX = pos().x();
			//posY = pos().y();
			//game->level->map->mapka[posX / 50 + 0][posY / 50 + 1]->setBrush(QPixmap(":/images/brown.png"));
			//game->level->map->mapa[posY / 50 + 1][posX / 50 + 0] = 3;
			//game->level->map->mapka[posX / 50][posY / 50]->setBrush(QPixmap(":/images/white.png"));
			//game->level->map->mapa[posY / 50][posX / 50] = 0;
		}
	}
	else if (game->level->map->mapa[posY / 50 + 1][posX / 50 + 0] != 1) {
		setPos(x(), y() + 50);
	}

	rectangle->setBrush(QPixmap(":/images/PlayerDown.png"));
}

////////////////////////

void Player::moveLeft3(std::vector<Box *> &pudelka, std::vector<Wall *> &sciany) {
	int posX = pos().x();
	int posY = pos().y();

	std::pair<bool, int> isBox = wyszukajPudelka(pudelka, posX, posY, '-', 'h', 50);
	bool isWall = wyszukajSciany(sciany, posX, posY, '-', 'h', 100);
	std::pair<bool, int> isBox2 = wyszukajPudelka(pudelka, posX, posY, '-', 'h', 100);

	if (isBox.first) {
		if (!isWall && !isBox2.first/* nie ma sciany && nie ma drugiego pudelka*/) {
			setPos(x() - 50, y());
			pudelka[isBox.second]->setPosition(pudelka[isBox.second]->getPosition().first - 50, pudelka[isBox.second]->getPosition().second);
		}
	}
	else if (!wyszukajSciany(sciany, posX, posY, '-', 'h', 50)) {
		setPos(x() - 50, y());
	}

	rectangle->setBrush(QPixmap(":/images/PlayerLeft.png"));
}

void Player::moveRight3(std::vector<Box *> &pudelka, std::vector<Wall *> &sciany){
	int posX = pos().x();
	int posY = pos().y();

	std::pair<bool, int> isBox = wyszukajPudelka(pudelka, posX, posY, '+', 'h', 50);
	bool isWall = wyszukajSciany(sciany, posX, posY, '+', 'h', 100);
	std::pair<bool, int> isBox2 = wyszukajPudelka(pudelka, posX, posY, '+', 'h', 100);

	if (isBox.first) {
		if (!isWall && !isBox2.first/* nie ma sciany && nie ma drugiego pudelka*/) {
			setPos(x() + 50, y());
			pudelka[isBox.second]->setPosition(pudelka[isBox.second]->getPosition().first + 50, pudelka[isBox.second]->getPosition().second);
		}
	}
	else if (!wyszukajSciany(sciany, posX, posY, '+', 'h', 50)) {
		setPos(x() + 50, y());
	}

	rectangle->setBrush(QPixmap(":/images/PlayerRight.png"));
}

void Player::moveUp3(std::vector<Box *> &pudelka, std::vector<Wall *> &sciany){
	int posX = pos().x();
	int posY = pos().y();

	std::pair<bool, int> isBox = wyszukajPudelka(pudelka, posX, posY, '-', 'v', 50);
	bool isWall = wyszukajSciany(sciany, posX, posY, '-', 'v', 100);
	std::pair<bool, int> isBox2 = wyszukajPudelka(pudelka, posX, posY, '-', 'v', 100);

	if (isBox.first) {
		if (!isWall && !isBox2.first/* nie ma sciany && nie ma drugiego pudelka*/) {
			setPos(x(), y() - 50);
			pudelka[isBox.second]->setPosition(pudelka[isBox.second]->getPosition().first, pudelka[isBox.second]->getPosition().second - 50);
		}
	}
	else if (!wyszukajSciany(sciany, posX, posY, '-', 'v', 50)) {
		setPos(x(), y() - 50);
	}

	rectangle->setBrush(QPixmap(":/images/PlayerUp.png"));
}

void Player::moveDown3(std::vector<Box *> &pudelka, std::vector<Wall *> &sciany){
	int posX = pos().x();
	int posY = pos().y();

	std::pair<bool, int> isBox = wyszukajPudelka(pudelka, posX, posY, '+', 'v', 50);
	bool isWall = wyszukajSciany(sciany, posX, posY, '+', 'v', 100);
	std::pair<bool, int> isBox2 = wyszukajPudelka(pudelka, posX, posY, '+', 'v', 100);

	if (isBox.first) {
		if (!isWall && !isBox2.first/* nie ma sciany && nie ma drugiego pudelka*/) {
			setPos(x(), y() + 50);
			pudelka[isBox.second]->setPosition(pudelka[isBox.second]->getPosition().first, pudelka[isBox.second]->getPosition().second + 50);
		}
	}
	else if (!wyszukajSciany(sciany, posX, posY, '+', 'v', 50)) {
		setPos(x(), y() + 50);
	}

	rectangle->setBrush(QPixmap(":/images/PlayerDown.png"));
}

/// <summary>
/// 
/// </summary>
/// <param name="sciany"></param>
/// <param name="posX"></param>
/// <param name="posY"></param>
/// <returns></returns>

bool Player::wyszukajSciany(std::vector<Wall *> &sciany, int posX, int posY, char c, char d, int distance){
	for (int i = 0; i < sciany.size(); i++) {
		if (d == 'h') {
			if (c == '-') {
				if (posX >= sciany[i]->getPosition().first && posY == sciany[i]->getPosition().second) {
					if (posX - sciany[i]->getPosition().first == distance) {
						return true; // is Wall
					}
				}
			}
			else {
				if (posX <= sciany[i]->getPosition().first && posY == sciany[i]->getPosition().second) {
					if (sciany[i]->getPosition().first - posX == distance) {
						return true; // is Wall
					}
				}
			}
		}
		else {
			if (c == '-') {
				if (posX == sciany[i]->getPosition().first && posY >= sciany[i]->getPosition().second) {
					if (posY - sciany[i]->getPosition().second == distance) {
						return true; // is Wall
					}
				}
			}
			else {
				if (posX == sciany[i]->getPosition().first && posY <= sciany[i]->getPosition().second) {
					if (sciany[i]->getPosition().second - posY == distance) {
						return true; // is Wall
					}
				}
			}
		}
		
	}

	return false; // is not Wall
}


std::pair<bool, int> Player::wyszukajPudelka(std::vector<Box *> &pudelka, int posX, int posY, char c, char d, int distance){
	for (int i = 0; i < pudelka.size(); i++) {
		if (d == 'h') {
			if (c == '-') {
				if (posX >= pudelka[i]->getPosition().first && posY == pudelka[i]->getPosition().second) {
					if (posX - pudelka[i]->getPosition().first == distance) {
						return std::make_pair(true, i); // is Box
					}
				}
			}
			else {
				if (posX <= pudelka[i]->getPosition().first && posY == pudelka[i]->getPosition().second) {
					if (pudelka[i]->getPosition().first - posX == distance) {
						return std::make_pair(true, i); // is Box
					}
				}
			}
		}
		else {
			if (c == '-') {
				if (posX == pudelka[i]->getPosition().first && posY >= pudelka[i]->getPosition().second) {
					if (posY - pudelka[i]->getPosition().second == distance) {
						return std::make_pair(true, i); // is Box
					}
				}
			}
			else {
				if (posX == pudelka[i]->getPosition().first && posY <= pudelka[i]->getPosition().second) {
					if (pudelka[i]->getPosition().second - posY == distance) {
						return std::make_pair(true, i); // is Box
					}
				}
			}
		}

	}

	return std::make_pair(false, 0); // is not Box
}
