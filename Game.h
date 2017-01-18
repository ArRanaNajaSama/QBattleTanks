#pragma once

#include <QVector>

#include "Tanks/PlayerTank.h"
#include "Tanks/EnemyTank.h"
#include "Field/BaseElement.h"


class Game
{
public:
    Game(char* path);
    ~Game();
    PlayerTank *getPlayer();

    //public methods
    int check(int, int);
    void destroyEnemyTank(BaseTank*);
    void destroySceneObject(BaseElement* element);
    void displayGameOverWindow();

private:
    PlayerTank *player;
    EnemyTank *enemy = NULL;
    QVector <int> fMatrix;
    QVector <EnemyTank*> enemies;
    QVector <BaseElement*> elements;
};

