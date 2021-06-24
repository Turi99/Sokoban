#include "Map.h"
#include <QGraphicsRectItem>
#include <qfile.h>
#include <fstream>
#include "Game.h"
#include <QMessageBox>

#include <qpainter.h>

extern Game *game;

Map::Map(QGraphicsItem *parent) :QObject(), QGraphicsRectItem(parent) {
	//QFile file("D:\\Piotr\\MVS\\c++\\c++ QT\\Sokoban\\Sokoban\\images\\map2.txt");

	/*for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			mapa[i][j] = 0;
		}
	}*/

	std::fstream plikMacierz;
	plikMacierz.open("D:\\Piotr\\MVS\\c++\\c++ QT\\Sokoban\\Sokoban\\images\\map2.txt",std::ios::in);

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

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			mapka[j][i] = new QGraphicsRectItem(this);
			mapka[j][i]->setRect(j*50, i*50, 50, 50);
			//mapka[i][j]->setTransformOriginPoint(0, 0);

			//mapka[i][j]->setFlag(QGraphicsItem::ItemIsFocusable);
			//mapka[i][j]->setFocus();
			if (mapa[i][j] == 0){
				mapka[j][i]->setBrush(QPixmap(":/images/white.png"));
			}
			else if(mapa[i][j] == 1){
				mapka[j][i]->setBrush(QPixmap(":/images/black.png"));
			}
			else if (mapa[i][j] == 2) {
				mapka[j][i]->setBrush(QPixmap(":/images/coin.png"));
			}
			else if (mapa[i][j] == 3) {
				mapka[j][i]->setBrush(QPixmap(":/images/brown.png"));
			}
			

			/*QLabel *l = new QLabel();
			l->setGeometry(j * 50 + 10, i * 50 + 10, 20, 20);
			l->setText(QString::number(i)+" "+ QString::number(j));*/
		}
	}
	//QBrush c = mapka[0][0]->brush();
	//QColor color = c.color();
	//color.rgb();
	/*QString str = "";
	QString str2 = "";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			str += QString::number(mapa[i][j])+" ";
			
			if (mapa[i][j] == 0) {
				//mapka[i][j]->setBrush(QPixmap(":/images/white.png"));
				str2 += QString::number(0) + " ";
			}
			else if (mapa[i][j] == 1) {
				//mapka[i][j]->setBrush(QPixmap(":/images/black.png"));
				str2 += QString::number(1) + " ";
			}
			else if (mapa[i][j] == 2) {
				//mapka[i][j]->setBrush(QPixmap(":/images/coin.png"));
				str2 += QString::number(2) + " ";
			}
			else if (mapa[i][j] == 3) {
				//mapka[i][j]->setBrush(QPixmap(":/images/brown.png"));
				str2 += QString::number(3) + " ";
			}

			//str2 += QString::number(mapka[i][j])+" ";
		}
		str += "\n";
		str2 += "\n";
	}
	str += "\n";
	str += str2;*/
	//QMessageBox::information(game, "tytul", str);
}

std::pair<int, int> Map::getCoordinates(int x, int y){
	return std::make_pair(x/50, y/50);
}

int Map::getNumber(int x, int y){
	//return mapa[x / 50][y / 50];
	return 0;
}

int Map::getCoinCount(){
	int ile = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			mapa[i][j] == 2 ? ile += 1 : ile += 0;
		}
	}
	return ile;
}
