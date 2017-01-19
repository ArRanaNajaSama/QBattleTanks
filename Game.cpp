#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "Game.h"
#include "Tanks/TankFactory.h"
#include "Field/BaseElement.h"

#define elementSize 50
#define fheigth 13
#define fwidth 13
#define fieldSize 650

Game::Game(char *path)
{
    //set scene
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    scene->setBackgroundBrush(Qt::black);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(fieldSize, fieldSize);
    scene->setSceneRect(0, 0, fieldSize, fieldSize);

    //load matrixes
    QFile* file = new QFile(path);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "File in not opened!";
    }
    QTextStream in(file);
    while(!in.atEnd())
    {
        QString temp;
        in >> temp;
        for(int i = 0; i < fwidth; i++)
        {
            fMatrix.push_back(temp[i].digitValue());
        }
    }

    //go through fieldMatrix and in acc with its data fill elements;
    for (int i = 0; i < fheigth; i++)
    {
        for (int j = 0; j < fwidth; j++)
        {
            switch(fMatrix[i+j*fwidth]){
            case 0:
                elements.push_back(BaseElement::makeElement(tileID,j,i));
                scene->addItem(elements.back());
                break;
            case 1:
                elements.push_back(BaseElement::makeElement(wallID,j,i));
                scene->addItem(elements.back());
                break;
            case 2:
                elements.push_back(BaseElement::makeElement(armoredWallID,j,i));
                scene->addItem(elements.back());
                break;
            case 3:
                elements.push_back(BaseElement::makeElement(headquartersID,j,i));
                scene->addItem(elements.back());
                break;
            default:
                elements.push_back(NULL);
                break;
            }
        }
    }

    //create player
    player = (PlayerTank*)TankFactory::makeTank(PlayerID);
    qDebug() << "player created";
    player->setRect(0, 0, 50, 50);
    player->setBrush(Qt::green);
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    qDebug() << "Focus is on player";

    //enemy positions
    for(int i=0; i < fheigth;i++)
    {
        for (int j = 0; j < fwidth;j++)
        {
            if (fMatrix[i+j*fwidth] == 4)
            {
                fMatrix[i+j*fwidth] = 0;
                player->setPos(i*elementSize,j*elementSize);
            }
            if (fMatrix[i+j*fwidth] == 5)
            {
                fMatrix[i+j*fwidth] = 0;
                enemy = (EnemyTank*)TankFactory::makeTank(EnemyID);
                enemy->setRect(0, 0, 50, 50);
                enemy->setBrush(* new QBrush(Qt::red));
                enemies.push_back(enemy);
                scene->addItem(enemy);;
                enemy->setPos(i*elementSize,j*elementSize);
            }
        }
    }
}


Game::~Game()
{
    //remove player
    scene->removeItem(player);
    delete player;

    //remove all elements from scene
    for (int i=0; i < elements.size(); i++)
    {
        scene->removeItem(elements[i]);
        delete elements[i];
    }

    //message
    scene->setBackgroundBrush(Qt::white);
    scene->addText("Game over!");

    // clean all enemies at the end;
    EnemyTank* enemy = NULL;
    while(enemies.size())
    {
        enemy = enemies.back();
        scene->removeItem(enemy);
        delete enemy;
        enemies.pop_back();
    }
}

int Game::check(int k, int m)
{
    int pos = k+m*fwidth;
    if (fMatrix[pos] != 0)
    {
        return 0;

    } else {
        return 1;
    }
}

void Game::destroyEnemyTanks(BaseTank *tobeDestroyed)
{
        for(int i = 0; i < enemies.size();i++)
            if (enemies[i] == tobeDestroyed)
            {
                delete enemies[i];
                enemies.erase(enemies.begin() + i);
                if (enemies.empty())
                {
                    delete this;
                }
            }
        return;
}





