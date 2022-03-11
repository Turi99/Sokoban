#include "Map.h"
#include <QGraphicsRectItem>
#include <qfile.h>
#include <fstream>
#include "Game.h"
#include <QMessageBox>

#include <qpainter.h>

#include <vector>

extern Game *game;

Map::Map(QGraphicsItem *parent) :QObject(), QGraphicsRectItem(parent) {
	std::fstream plikMacierz;
	plikMacierz.open("..\\Sokoban\\images\\map1.txt", std::ios::in);

	if (!plikMacierz.good()) {
		//std::cerr << "Nie mozna otworzyc pliku, lub nie istnieje\n";
	}
	else {
		while (!plikMacierz.eof()) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					plikMacierz >> mapa[i][j];
				}
			}
		}
	}

	//std::vector<std::vector<Box *>> pudelka(10, std::vector<Box *>(10, nullptr));

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			//std::vector<std::unique_ptr<Box>> list;
			//std::vector<Box *> list;
			mapka[j][i] = new QGraphicsRectItem(this);
			mapka[j][i]->setRect(j * 50, i * 50, 50, 50);
			//mapka[i][j]->setTransformOriginPoint(0, 0);

			if (mapa[i][j] == 0) {
				//mapka[j][i]->setBrush(QPixmap(":/images/Wall2.png"));
				//mapka[j][i]->setBrush(QPixmap(":/image/white.png"));
				mapka[j][i]->setBrush(QPixmap("image\\white.png"));
			}
			else if (mapa[i][j] == 1) {
				//mapka[j][i]->setBrush(QPixmap(":/images/Wall.png"));
				mapka[j][i]->setBrush(QPixmap("image\\Wall.png"));
			}
			else if (mapa[i][j] == 2) {
				//mapka[j][i]->setBrush(QPixmap(":/images/coin.png"));
				mapka[j][i]->setBrush(QPixmap("image\\coin.png"));
			}
			else if (mapa[i][j] == 3) {
				//mapka[j][i]->setBrush(QPixmap(":/images/brown.png"));
				mapka[j][i]->setBrush(QPixmap("image\\brown.png"));
			}
		}
	}
}

Map::Map(QGraphicsItem *parent, int val) :QObject(), QGraphicsRectItem(parent) {
	std::fstream plikMacierz;

	std::string filename1 = "..\\images\\map1.txt";
	std::string filename2 = "..\\images\\map2.txt";
	std::string filename3 = "..\\images\\map3.txt";

	if (val == 1) {
		plikMacierz.open("images\\map1.txt", std::ios::in);
	}
	else if (val == 2) {
		plikMacierz.open("images\\map2.txt", std::ios::in);
	}
	else if (val == 3) {
		plikMacierz.open("images\\map3.txt", std::ios::in);
	}
	else if (val == 4) {
		plikMacierz.open("images\\map4.txt", std::ios::in);
	}

	if (!plikMacierz.good()) {
		//std::cerr << "Nie mozna otworzyc pliku, lub nie istnieje\n";
	}
	else {
		while (!plikMacierz.eof()) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					plikMacierz >> mapa[i][j];
				}
			}
		}
	}

	//std::vector<std::vector<Box *>> pudelka(10, std::vector<Box *>(10, nullptr));

	int ilePudelek = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			mapka[j][i] = new QGraphicsRectItem(this);
			mapka[j][i]->setRect(j*50, i*50, 50, 50);
			//mapka[i][j]->setTransformOriginPoint(0, 0);
			
			if (mapa[i][j] == 0){
				//mapka[j][i]->setBrush(QPixmap(":/images/Wall2.png"));
				//mapka[j][i]->setBrush(QPixmap(":/images/white.png"));
				mapka[j][i]->setBrush(QPixmap("images\\white.png"));
			}
			else if(mapa[i][j] == 1){
				//mapka[j][i]->setBrush(QPixmap(":/images/Wall.png"));
				//game->level->ileScian+=1;
			}
			else if (mapa[i][j] == 2) {
				//mapka[j][i]->setBrush(QPixmap(":/images/coin.png"));
				//mapka[j][i]->setBrush(QPixmap(":/images/white.png"));
				mapka[j][i]->setBrush(QPixmap("images\\white.png"));
				//game->level->ilePunktow+=1;
			}
			else if (mapa[i][j] == 3) {
				mapka[j][i]->setBrush(QPixmap("images\\white.png"));
				ilePudelek++;
				// game->level->coordsBoxs.push_back(std::make_pair(j * 50, i * 50));
				//list.push_back(new Box(this, j * 50, i * 50));
				//game->level->boxs2.push_back(new Box(this, j * 50, i * 50));
			}
			
		}
		
	}

}

//////////////////////////////////////

std::pair<int, int> Map::getCoordinates(int x, int y){
	return std::make_pair(x/50, y/50);
}
//////////////////////////////////////

int Map::getCoinCount(){
	int ile = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			mapa[i][j] == 2 ? ile += 1 : ile += 0;
		}
	}
	return ile;
}

std::vector<std::pair<int, int>> Map::getCoordsBox(){
	std::vector<std::pair<int, int>> kordy;
	kordy.clear();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (mapa[i][j] == 0) {
				//	
			}
			else if (mapa[i][j] == 1) {
				//game->level->ileScian+=1;
			}
			else if (mapa[i][j] == 2) {
				//game->level->ilePunktow+=1;
			}
			else if (mapa[i][j] == 3) {
				kordy.push_back(std::make_pair(j * 50, i * 50));
			}
		}
	}

	return kordy;
}

std::vector<std::pair<int, int>> Map::getCoordsPoint(){
	std::vector<std::pair<int, int>> kordy;
	kordy.clear();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (mapa[i][j] == 2) {
				kordy.push_back(std::make_pair(j * 50, i * 50));
			}
		}
	}

	return kordy;
}

std::vector<std::pair<int, int>> Map::getCoordsWall(){
	std::vector<std::pair<int, int>> kordy;
	kordy.clear();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (mapa[i][j] == 1) {
				kordy.push_back(std::make_pair(j * 50, i * 50));
			}
		}
	}

	return kordy;
}
