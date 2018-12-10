#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QGraphicsTextItem>
#include <QUrl>
#include <QTimer>
#include "player.h"//<QGraphicsRectItem>
#include "movement.h"
#include "ball.h"

class Game : public QObject
{
    Q_OBJECT
private:
    QMediaPlayer *music;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *updateTimer;
    Player *player;
    Player *player2;
    Movement *move;
    Ball *ball;
    bool sceneC = false;
    QGraphicsTextItem *score1;
    QGraphicsTextItem *score2;
    int player1Score = 0;
    int player2Score = 0;

public:
    Game();
public slots:
    void changeScene();
    void updateCamera();
    void Points(int side);
    int getScore1(int player1Score);
    int getScore2(int player2Score);
    void winGame();
};

#endif // GAME_H
