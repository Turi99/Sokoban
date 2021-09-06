#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QGraphicsRectItem>

class GameMenu: public QGraphicsRectItem {

public:
	GameMenu(QGraphicsItem *parent = 0);
	QGraphicsRectItem *menu;
};

#endif // !GAMEMENU_H
