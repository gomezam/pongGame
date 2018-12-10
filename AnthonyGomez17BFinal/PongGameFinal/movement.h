#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <qgraphicsitem.h>
#include "player.h"


class Movement: public QObject, public QGraphicsItem {
    Q_OBJECT
private:
    Player* player1;
    Player* player2;


public:
    Movement(Player* player, Player* player2);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
signals:
    void changeScene();
};

#endif // MOVEMENT_H
