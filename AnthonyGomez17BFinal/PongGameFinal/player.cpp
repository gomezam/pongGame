#include "player.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <qmath.h>
#include <QTimer>
#include "ball.h"


Player::Player(int pad):pad(pad)
{
    if (pad == 1)
    {
    setPixmap(QPixmap(":/Images/pongPaddle1.png"));
    }
    if (pad == 2)
    {
    setPixmap(QPixmap(":/Images/pongPaddle2.png"));
    }

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this, SLOT(update()));
    timer->start(50);
    vX = 0;
    vY = 0;
    tX = 0;
    tY = 0;
   // friction = 0.02f;

}


void Player::keyPressEvent(QKeyEvent *event)
{
/*
    if(event->key() == Qt::Key_Left)
    {
       vX += -1;
    }
    if(event->key() == Qt::Key_Right)
    {
       vX += 1;
    }
    */

    qDebug() << event->key();
    qDebug() << pad;
    if(pad == 1)
    {
     if(event->key() == Qt::Key_W)
     {
         vY = -15;
      }
      if(event->key() == Qt::Key_S)
      {
        vY = 15;
     }
    }

    if(pad == 2)
    {
     if(event->key() == Qt::Key_O)
     {
        vY = -15;
     }
     if(event->key() == Qt::Key_K)
     {
        vY = 15;
      }
    }

}


void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(pad == 1)
    {
    if(event->key() == Qt::Key_W)
    {
       vY = 0;
    }
    if(event->key() == Qt::Key_S)
    {
       vY = 0;
    }
    }

    if(pad == 2)
    {
        if(event->key() == Qt::Key_O)
        {
           vY = 0;
     }
     if(event->key() == Qt::Key_K)
     {
           vY = 0;
     }
    }

}

void Player::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    tX = event->scenePos().x();
    tY = event->scenePos().y();
    qDebug() << "vx" << tX << "vy" << tY;
}

void Player::update()
{
   //qDebug() << "vx" << vX << "vy" << vY;
   // vX*=(1-friction);
   // vY*=(1-friction);
    setPos(x(), y() +vY);
}
