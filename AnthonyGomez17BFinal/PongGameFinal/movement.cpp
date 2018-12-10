#include "movement.h"
#include <QKeyEvent>
#include <QDebug>

Movement::Movement(Player* player1, Player* player2) : player1(player1), player2(player2)
{

}

void Movement::keyPressEvent(QKeyEvent *event) {
    //qDebug() << event;
    if(event->key() == Qt::Key_B)
    {
        exit(0) ;
    }

    if(event->key() == Qt::Key_C)
    {
        emit changeScene();
    }

    player1->keyPressEvent(event);
    player2->keyPressEvent(event);
}

void Movement::keyReleaseEvent(QKeyEvent *event) {
    //qDebug() << event;
    player1->keyReleaseEvent(event);
    player2->keyReleaseEvent(event);
}

QRectF Movement::boundingRect() const {
    return QRectF(0, 0, 800, 800);
}

void Movement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

}
