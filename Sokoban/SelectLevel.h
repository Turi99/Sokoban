#ifndef SELECTLEVEL_H
#define SELECTLEVEL_H

#include <QGraphicsRectItem>
#include <qobject.h>
#include <qgraphicsitem.h>

class SelectLevel : /*public QObject,*/ public QGraphicsRectItem {
	//Q_OBJECT
public:
	SelectLevel(QGraphicsItem *parent = 0);
	QGraphicsRectItem *selectLevelScene;
	void setCursorPosition(int val);
	int getCursorPosition();

protected:
	void keyPressEvent(QKeyEvent *event) override;

private:
	QGraphicsTextItem *text1, *lvl1, *lvl2;
	QGraphicsRectItem *arrow;

	int cursorPosition = 1;
	void setArrow(int val);
};

#endif // !SELECTLEVEL_H
