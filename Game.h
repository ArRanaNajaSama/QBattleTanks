#pragma once

#include <QGraphicsView>
#include <QWidget>
#include <QVector>

#include "Tanks/PlayerTank.h"
#include "Tanks/EnemyTank.h"
#include "Field/Wall.h"

class Game: public QGraphicsView
{
public:
    Game(QWidget * parent = 0);
    PlayerTank *getPlayer();

private:
    PlayerTank *player;
    EnemyTank *enemy = NULL;
    QVector <EnemyTank*> enemies;
    Wall *wall;
};

