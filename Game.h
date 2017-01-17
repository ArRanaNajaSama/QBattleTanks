#pragma once

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QVector>

#include "Tanks/PlayerTank.h"
#include "Tanks/EnemyTank.h"

class Game: public QGraphicsView
{
public:
    Game(QWidget * parent = 0);
    QGraphicsScene * scene;
    PlayerTank *getPlayer();

private:
    PlayerTank *player;
    EnemyTank *enemy = NULL;
    QVector <EnemyTank*> enemies;
};

