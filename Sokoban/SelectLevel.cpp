#include "SelectLevel.h"
#include "Game.h"
#include <QKeyEvent>
#include <qmessagebox.h>

extern Game *game;

SelectLevel::SelectLevel(QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent) {
	selectLevelScene = new QGraphicsRectItem(this);
	selectLevelScene->setTransformOriginPoint(0, 0);
	selectLevelScene->setRect(0, 0, 620, 520);
	selectLevelScene->setFlag(QGraphicsItem::ItemIsFocusable);
	selectLevelScene->setFocus();
	selectLevelScene->setBrush(QColor(Qt::green));

	text1 = new QGraphicsTextItem(selectLevelScene);
	text1->setPos(20, 20);
	text1->setPlainText("Select Level");

}

void SelectLevel::keyPressEvent(QKeyEvent *event){
	if(event->key() == Qt::Key_A){
		QMessageBox::information(game, "", "Click key A");
	}
}
