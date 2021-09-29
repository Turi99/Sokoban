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

/*void Player::keyPressEvent(QKeyEvent *event){
	
	if (event->key() == Qt::Key_Escape) {
		//QMessageBox::information(game, "", "escape");
		if (game->level->gameMenu == nullptr) {
			//game->gameMenu = new GameMenu();
			//game->scene->addItem(game->gameMenu);
			//game->level->gameMenu = new GameMenu(game->level);
			//QMessageBox::information(game, "", "jest");
		}
		else {
			delete game->level->gameMenu;
			game->level->gameMenu = nullptr;
			QMessageBox::information(game, "", "niema");
		}
	}
	else {
		int posX = pos().x();
		int posY = pos().y();

	
		if (event->key() == Qt::Key_A) {
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
		}
		else if (event->key() == Qt::Key_D) {
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
		}
		else if (event->key() == Qt::Key_W) {
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
		}
		else if (event->key() == Qt::Key_S) {
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
		}
	
		game->level->coinCount->setPlainText("Coin counts: " + QString::number(game->level->map->getCoinCount()));

		if (game->level->map->getCoinCount() == 0) {
			game->level->coinCount->setPlainText("Coin counts: " + QString::number(game->level->map->getCoinCount()) + "\n" + "Koniec poziomu");
		}

	}

}*/

void Player::moveLeft(){
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

	//rectangle->setTransformOriginPoint(0, 180);

	/*game->level->coinCount->setPlainText("Coin counts: " + QString::number(game->level->map->getCoinCount()));

	if (game->level->map->getCoinCount() == 0) {
		game->level->coinCount->setPlainText("Coin counts: " + QString::number(game->level->map->getCoinCount()) + "\n" + "Koniec poziomu");
	}*/

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
	
	/*game->level->coinCount->setPlainText("Coin counts: " + QString::number(game->level->map->getCoinCount()));

	if (game->level->map->getCoinCount() == 0) {
		game->level->coinCount->setPlainText("Coin counts: " + QString::number(game->level->map->getCoinCount()) + "\n" + "Koniec poziomu");
	}*/

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

	/*game->level->coinCount->setPlainText("Coin counts: " + QString::number(game->level->map->getCoinCount()));

	if (game->level->map->getCoinCount() == 0) {
		game->level->coinCount->setPlainText("Coin counts: " + QString::number(game->level->map->getCoinCount()) + "\n" + "Koniec poziomu");
	}*/

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

	/*game->level->coinCount->setPlainText("Coin counts: " + QString::number(game->level->map->getCoinCount()));

	if (game->level->map->getCoinCount() == 0) {
		game->level->coinCount->setPlainText("Coin counts: " + QString::number(game->level->map->getCoinCount()) + "\n" + "Koniec poziomu");
		//game->level->levelNumber++;

		//if (game->level->levelNumber <= 4) {
			//game->level->nextLevel(game->level->levelNumber);
		//}

		//delete game->level->player;
		//delete game->level->map;

		//game->level->createLevel(game->level->levelNumber); // = new Level(0, game->level->levelNumber);

	}*/

}
	
	/*Map m;
	int posX = pos().x();
	int posY = pos().y();
	

	if (event->key() == Qt::Key_A) {
		if (game->map->mapa[posY / 50 - 0][posX / 50 - 1] == 3) {
			
			if (game->map->mapa[posY / 50 - 0][posX / 50 - 2] != 1 && game->map->mapa[posY / 50 - 0][posX / 50 - 2] != 3) {
				setPos(x() - 50, y());
				posX = pos().x();
				posY = pos().y();
				game->map->mapka[posX / 50 - 1][posY / 50 - 0]->setBrush(QPixmap(":/images/brown.png"));
				game->map->mapa[posY / 50 - 0][posX / 50 - 1] = 3;
				game->map->mapka[posX / 50][posY / 50]->setBrush(QPixmap(":/images/white.png"));
				game->map->mapa[posY / 50][posX / 50] = 0;
			}
			//else {
				//QMessageBox::information(game, "", "mie mozna przesunac pudelka");
			//}
		}
		else if (game->map->mapa[posY / 50 - 0][posX / 50 - 1] != 1) {
			setPos(x() - 50, y());
		}
		
	}
	else if (event->key() == Qt::Key_D) {
		if (game->map->mapa[posY / 50 - 0][posX / 50 + 1] == 3) {

			if (game->map->mapa[posY / 50 - 0][posX / 50 + 2] != 1 && game->map->mapa[posY / 50 - 0][posX / 50 + 2] != 3) {
				setPos(x() + 50, y());
				posX = pos().x();
				posY = pos().y();
				game->map->mapka[posX / 50 + 1][posY / 50 - 0]->setBrush(QPixmap(":/images/brown.png"));
				game->map->mapa[posY / 50 - 0][posX / 50 + 1] = 3;
				game->map->mapka[posX / 50][posY / 50]->setBrush(QPixmap(":/images/white.png"));
				game->map->mapa[posY / 50][posX / 50] = 0;
			}
			//else {
				//QMessageBox::information(game, "", "mie mozna przesunac pudelka");
			//}
		}
		else if (game->map->mapa[posY / 50 - 0][posX / 50 + 1] != 1) {
			setPos(x() + 50, y());
		}
	}
	else if (event->key() == Qt::Key_W) {
		if (game->map->mapa[posY / 50 - 1][posX / 50 + 0] == 3) {

			if (game->map->mapa[posY / 50 - 2][posX / 50 + 0] != 1 && game->map->mapa[posY / 50 - 2][posX / 50 - 0] != 3) {
				setPos(x(), y() - 50);
				posX = pos().x();
				posY = pos().y();
				game->map->mapka[posX / 50 + 0][posY / 50 - 1]->setBrush(QPixmap(":/images/brown.png"));
				game->map->mapa[posY / 50 - 1][posX / 50 + 0] = 3;
				game->map->mapka[posX / 50][posY / 50]->setBrush(QPixmap(":/images/white.png"));
				game->map->mapa[posY / 50][posX / 50] = 0;
			}
			//else {
				//QMessageBox::information(game, "", "mie mozna przesunac pudelka");
			//}
		}
		else if (game->map->mapa[posY / 50 - 1][posX / 50 + 0] != 1) {
			setPos(x(), y() - 50);
		}
	}
	else if (event->key() == Qt::Key_S) {
		if (game->map->mapa[posY / 50 + 1][posX / 50 + 0] == 3) {

			if (game->map->mapa[posY / 50 + 2][posX / 50 + 0] != 1 && game->map->mapa[posY / 50 + 2][posX / 50 - 0] != 3) {
				setPos(x(), y() + 50);
				posX = pos().x();
				posY = pos().y();
				game->map->mapka[posX / 50 + 0][posY / 50 + 1]->setBrush(QPixmap(":/images/brown.png"));
				game->map->mapa[posY / 50 + 1][posX / 50 + 0] = 3;
				game->map->mapka[posX / 50][posY / 50]->setBrush(QPixmap(":/images/white.png"));
				game->map->mapa[posY / 50][posX / 50] = 0;
			}
			//else {
				//QMessageBox::information(game, "", "mie mozna przesunac pudelka");
			}//
		}
		else if (game->map->mapa[posY / 50 + 1][posX / 50 + 0] != 1) {
			setPos(x(), y() + 50);
		}
	}
	
	std::pair<int,int> xy = m.getCoordinates(pos().x(),pos().y());

	game->l->setText(QString::number(pos().x())+" "+ QString::number(pos().y()));
	game->txt->setPlainText(QString::number(pos().x())+" "+ QString::number(pos().y()));
	game->l2->setText(QString::number(xy.first+1) + " " + QString::number(xy.second+1));
	game->l4->setText("Coin counts: "+QString::number(game->map->getCoinCount()));

	if (game->map->getCoinCount() == 0) {
		QMessageBox::information(game, "", "Koniec gry");
		game->l4->setText("Coin counts: " + QString::number(game->map->getCoinCount())+"\n"+"Koniec poziomu");
		// /*QGraphicsRectItem *tlo = new QGraphicsRectItem(this);
		//tlo->setRect(0, 0, 600, 500);
		//tlo->setPos(0, 0);
		//tlo->setBrush(Qt::red);

		//exit(0);
	}*/


