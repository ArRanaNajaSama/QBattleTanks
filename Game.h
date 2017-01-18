#pragma once

#include <QGraphicsView>
#include <QVector>

#include "Tanks/PlayerTank.h"
#include "Tanks/EnemyTank.h"
#include "Field/BaseElement.h"


class Game: public QGraphicsView
{
public:
    Game(char* path);
    ~Game();
    PlayerTank *getPlayer();
    int check(int, int);
    void destroyEnemyTank(BaseTank*);

private:
    PlayerTank *player;
    EnemyTank *enemy = NULL;
    QVector <int> fMatrix;
    QVector <EnemyTank*> enemies;
    QVector <BaseElement*> elements;
};

