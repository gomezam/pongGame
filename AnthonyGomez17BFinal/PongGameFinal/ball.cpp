#include "ball.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include  <qmath.h>

Ball::Ball()
{
    setPixmap(QPixmap(":/Images/pongBall.png"));
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this, SLOT(Move()));
    timer->start(50);
    velocity = new QVector2D(5, 0);
    speed = 10;
    setTransformOriginPoint(boundingRect().width() / 2, boundingRect().height() / 2);
    hit = new QMediaPlayer();
    hit->setMedia((QUrl("qrc:/Audio/lasrhit1.mp3")));
    hit2 = new QMediaPlayer();
    hit2->setMedia((QUrl("qrc:/Audio/lasrhit2.mp3")));
    hit3 = new QMediaPlayer();
    hit3->setMedia((QUrl("qrc:/Audio/lasrhit4.mp3")));

}

void Ball::Move()
{
    setRotation(currentRotation);
    currentRotation += 10;

    velocity->normalize();
    velocity->operator *=( speed );

    setPos(x() + velocity->x(), y() + velocity->y());

    if(pos().y() <= 0 || pos().y() >= 600 - boundingRect().height() - 20)
    {
      velocity->setY(-velocity->y());
    }

    QList<QGraphicsItem*> colliding_items = collidingItems();
    int n = colliding_items.size();
    for(int i=0; i<n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Player))
        {
            velocity->setX(-velocity->x());
            velocity->setY(rand() % 20 - 10);
            if(speed <= 60)
              {  speed += 5; }

        if (Ball::form == false)
     {
            hitSound = rand() % 3;
            if(hitSound == 0)
            {
                hit->play();
            }
            else if(hitSound == 1)
            {
                hit2->play();
            }
            else
            {
                hit3->play();
            }
     }
            return;
        }
    }

    if(pos().x() <= 0 - boundingRect().width() || pos().x() >= 800 + boundingRect().width())
    {
        if(pos().x() <= 0 - boundingRect().width())
        {
                emit Points(1);
        }
        else
        {
            emit Points(2);
        }

        //qDebug() << " pintsdkgksflmklsg";
         //scene()->removeItem(this);
        // delete this;
        setPos(300, 400);
        speed = 10;

    }

}




