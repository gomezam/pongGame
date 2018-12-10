
#include <QApplication>
#include "game.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    Game *game = new Game();
    return a.exec();
}
