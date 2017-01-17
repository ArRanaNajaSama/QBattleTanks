#pragma once

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVector>

#include "Tanks/PlayerTank.h"
#include "Tanks/EnemyTank.h"
#include "Field/Wall.h"

class Game: public QGraphicsView
{
public:
    Game(QWidget * parent = 0);
    QGraphicsScene *scene;
    QGraphicsView *view;
    PlayerTank *getPlayer();

private:
    PlayerTank *player;
    EnemyTank *enemy = NULL;
    QVector <EnemyTank*> enemies;
    Wall *wall;
};

