#ifndef SELECTLEVEL_H
#define SELECTLEVEL_H

#include <QGraphicsRectItem>
#include <qobject.h>
#include <qgraphicsitem.h>

class SelectLevel : public QObject, public QGraphicsRectItem {
	Q_OBJECT
public:
	SelectLevel(QGraphicsItem *parent = 0);
	QGraphicsRectItem *selectLevelScene;

protected:
	void keyPressEvent(QKeyEvent *event) override;

private:
	QGraphicsTextItem *text1;

};

#endif // !SELECTLEVEL_H
