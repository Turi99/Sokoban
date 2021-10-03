#ifndef MAP_H
#define MAP_H

#include <QGraphicsRectItem>
#include <qobject.h>
#include <qgraphicsitem.h>
#include <qvector.h>
#include <QGraphicsPixmapItem>
#include <vector>

class Map :public QObject, public QGraphicsRectItem{
	Q_OBJECT
public:
	Map(QGraphicsItem *parent = 0);
	Map(QGraphicsItem *parent, int val);
	static std::pair<int, int> getCoordinates(int x, int y);
	
	int mapa[10][10];
	QGraphicsRectItem *mapka[10][10];
	int getCoinCount();
	//QGraphicsPixmapItem *mapka[10][10];
	std::vector<std::pair<int, int>> getCoordsBox();
	std::vector<std::pair<int, int>> getCoordsPoint();
	std::vector<std::pair<int, int>> getCoordsWall();
private:
	//QVector<QVector<QGraphicsRectItem *>> mapa;
};

#endif // !MAP_H
