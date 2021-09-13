#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QGraphicsRectItem>
#include <qobject.h>

class GameMenu: public QGraphicsRectItem {

public:
	GameMenu(QGraphicsItem *parent = 0);
	QGraphicsRectItem *gameMenu;
	QGraphicsTextItem *t1;

protected:
	void keyPressEvent(QKeyEvent *event) override;


};

#endif // !GAMEMENU_H
