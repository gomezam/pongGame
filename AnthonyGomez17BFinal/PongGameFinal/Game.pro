#-------------------------------------------------
#
# Project created by QtCreator 2015-02-16T17:57:51
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app


SOURCES += main.cpp\
    player.cpp \
    game.cpp \
    movement.cpp \
    ball.cpp

HEADERS  += \
    player.h \
    game.h \
    movement.h \
    ball.h

RESOURCES += \
    data.qrc
