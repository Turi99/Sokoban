#ifndef MAP_H
#define MAP_H

#include <QGraphicsRectItem>
#include <qobject.h>
#include <qgraphicsitem.h>
#include <qvector.h>
#include <QGraphicsPixmapItem>

class Map :public QObject, public QGraphicsRectItem{
	Q_OBJECT
public:
	Map(QGraphicsItem *parent = 0);
	static std::pair<int, int> getCoordinates(int x, int y);
	static int getNumber(int x, int y);
	
	int mapa[10][10];
	QGraphicsRectItem *mapka[10][10];
	int getCoinCount();
	//QGraphicsPixmapItem *mapka[10][10];
private:
	//QVector<QVector<QGraphicsRectItem *>> mapa;
};

#endif // !MAP_H
