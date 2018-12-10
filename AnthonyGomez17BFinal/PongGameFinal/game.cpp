
#include <QGraphicsScene>
#include "game.h"
#include "movement.h"
#include <QImage>
#include <QBrush>
#include <QRect>
#include <QDebug>
Game::Game()
{
    scene = new QGraphicsScene();
    // The rect


    // visualize the scene wsing a qWidget
    view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800,600); // set the secen outside
    view->setSceneRect(0,0,800,600); // the inner viewable rect
    view->setBackgroundBrush( QBrush(QImage(":/Images/newpongScreen.jpg")) );

    QString text = "Score : 0";
    QColor color;
    QFont font("Lucida Bright", 20, 1);

    score1 = new QGraphicsTextItem();
    score2 = new QGraphicsTextItem();
    score1->setDefaultTextColor(Qt::GlobalColor::red);
    score2->setDefaultTextColor(Qt::GlobalColor::blue);
    score1->setFont(font);
    score2->setFont(font);
    score1->setPlainText(text);
    score2->setPlainText(text);
    score1->setPos(0,515);
    score2->setPos(0,545);

    player = new Player(1);
    player2 = new Player(2);
    ball = new Ball();
    move = new Movement(player, player2);
    connect(move, SIGNAL(changeScene()),this,SLOT(changeScene()));
    connect(ball, SIGNAL(Points(int)), this, SLOT(Points(int)));

    scene->addItem(player2);
    scene->addItem(player);
    scene->addItem(move);
    scene->addItem(ball);
    scene->addItem(score1);
    scene->addItem(score2);
    move->setFlag(QGraphicsItem::ItemIsFocusable);
    move->setFocus();

    updateTimer = new QTimer();
    QObject::connect(updateTimer, SIGNAL(timeout() ), this, SLOT(updateCamera() ) );
    updateTimer->start(50);

    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/Audio/Dual.mp3"));
    music->play();


    player->setPos(0, (view->height() - player->boundingRect().height()) / 2);
    player2->setPos(view->width() - player2->boundingRect().width(), (view->height() - player->boundingRect().height())/ 2);
    ball->setPos(400, 400);
}


void Game::updateCamera()
{
   // view->setSceneRect(0,player->y()-400,800,600);

}
void Game::changeScene()
{
    if(sceneC == false)
    {
        view->setBackgroundBrush( QBrush(QImage(":/Images/pongScreen2.jpg")) );
        music->setMedia(QUrl("qrc:/Audio/Tetris.mp3"));
        music->play();
        player->setPixmap(QPixmap(":/Images/tetPad1.png"));
        player2->setPixmap(QPixmap(":/Images/tetPad2.png"));
        ball->setPixmap(QPixmap(":/Images/tetBall3.png"));
        ball->form = true;
    }
    else
    {
        view->setBackgroundBrush( QBrush(QImage(":/Images/newpongScreen.jpg")) );
        music->setMedia(QUrl("qrc:/Audio/Dual.mp3"));
        music->play();
        player->setPixmap(QPixmap(":/Images/pongPaddle1.png"));
        player2->setPixmap(QPixmap(":/Images/pongPaddle2.png"));
        ball->setPixmap(QPixmap(":/Images/pongBall.png"));
    }
    sceneC = !sceneC;
}
void Game::Points(int side)
{
    int s1;
    int s2;

    if(side == 1)
    {
        player2Score++;
    }
    else
    {
         player1Score++;
    }
    score1->setPlainText(QString("Score : %1").arg(player1Score));
    score2->setPlainText(QString("Score : %2").arg(player2Score));

    s1 = getScore1(player1Score);
    s2 = getScore2(player2Score);

    if(s1 >= 3 || s2 >= 3)
    {
        winGame();
    }

}

int Game::getScore1(int player1Score)
{
    int scor;
    scor = player1Score;
    return scor;
}

int Game::getScore2(int player2Score)
{
    int scor;
    scor = player2Score;
    return scor;
}

void Game::winGame()
{
    delete player;
    delete player2;
    delete ball;

     music->setMedia(QUrl("qrc:/Audio/ffviiVictory.mp3"));
     music->play();
     view->setBackgroundBrush( QBrush(QImage(":/Images/winScreen.jpg")) );

}
