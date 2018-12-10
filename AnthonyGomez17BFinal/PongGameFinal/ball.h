#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <QGraphicsRectItem>
#include <QObject>
#include<QVector2D>
#include <QMediaPlayer>
#include "player.h"

class Ball : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Player* player;
    QVector2D* velocity;
    float speed;
    int currentRotation = 0;
    int hitSound = 1;
    QMediaPlayer *hit;
    QMediaPlayer *hit2;
    QMediaPlayer *hit3;

public:
    Ball();
     bool form = false;
public slots:
    void Move();
signals:
    void Points(int side);
};

#endif // PROJECTILE_H
