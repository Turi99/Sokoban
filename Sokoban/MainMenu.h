#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsRectItem>
#include <qobject.h>
#include <qgraphicsitem.h>

class MainMenu : /*public QObject, */public QGraphicsRectItem{
	//Q_OBJECT
public:
	MainMenu(QGraphicsItem *parent = 0);
	QGraphicsRectItem *main;
	void setCursorPosition(int val);
	int getCursorPosition();

protected:
	void keyPressEvent(QKeyEvent *event) override;

private:
	int cursorPosition = 1;
	void setArrow(int val);


	QGraphicsTextItem *playTxt, *selectLevelTxt, *settingTxt, *quitTxt;
	QGraphicsRectItem *arrow1, *arrow2;
};

#endif // !MAINMENU_H
