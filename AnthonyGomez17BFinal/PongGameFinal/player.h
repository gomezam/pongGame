#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QUrl>
#include <QGraphicsSceneMouseEvent>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QMediaPlayer *shootSound;
    float vX;
    float vY;
    int pad;

public:
    float tX;
    float tY;
    float friction;

    Player(int pad);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
public slots:
    void update();
};

#endif // PLAYER_H
