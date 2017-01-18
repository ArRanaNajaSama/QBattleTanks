#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "Game.h"
#include "Tanks/TankFactory.h"
#include "Field/BaseElement.h"

QGraphicsScene *scene;
QGraphicsView *view;

#define elementSize 50
#define heigth 13
#define width 13
#define fieldSize 660

PlayerTank *Game::getPlayer()
{
    return player;
}

Game::Game(char *path)
{
    //set scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setBackgroundBrush(QPixmap(":/images/tile.jpg"));
    view = new QGraphicsView(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
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
        for(int i = 0; i < width; i++)
        {
            fMatrix.push_back(temp[i].digitValue());
        }
    }

    view->show();

    //create player
    player = (PlayerTank*)TankFactory::makeTank(PlayerID);
    qDebug() << "player created";
    player->setRect(0, 0, 50, 50);
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    qDebug() << "Focus is on player";

    //elements positions
    for(int i=0; i < heigth;i++)
        for (int j = 0; j < width;j++){
            if ( fMatrix[i+j*width] == 4)
                player->setPos(i*elementSize-2*elementSize,j*elementSize);
            if (fMatrix[i+j*width] == 5)
            {
                fMatrix[i+j*width] = 0;
                enemy = (EnemyTank*)TankFactory::makeTank(EnemyID);
                enemy->setRect(0, 0, 50, 50);
                enemies.push_back(enemy);
                scene->addItem(enemy);
                enemy->setPos(i*elementSize,j*elementSize);
            }
        }

    //go through fieldMatrix and in acc with its data fill elements;
    for (int i = 0; i < heigth; i++)
    {
        for (int j = 0; j < width; j++)
        {
            switch(fMatrix[i+j*width]){
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
}

Game::~Game()
{
    //remove all elements from scene
    for (int i=0; i < elements.size(); i++ )
    {
        scene()->removeItem(elements[i]);
        delete elements[i];
    }

    // clean all enemies at the end;
    EnemyTank* enemy = NULL;
    scene()->removeItem(player);
    delete player;
    scene()->setBackgroundBrush(QPixmap(":/images/white.jpg"));
    scene()->addText("GAME OVER!");
    while(enemies.size())
    {
        enemy = enemies.back();
        scene()->removeItem(player);
        delete player;
        enemies.pop_back();
    }
}

int Game::check(int a, int b)
{
    if (fMatrix[a+b*width] != 0)
    {
        return 0;
    }
    else
        return 1;
}

void Game::destroy(BaseElement* base)
{
    for(int i = 0 ; i < heigth; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (elements[i+j*width] == base){
                scene()->removeItem(elements[i+j*width]);
                delete elements[i+j*width];
                elements[i+j*width]=NULL;
                fMatrix[j+i*width] = 0;
            }
        }
    }
}

void Game::destroy(int i, int j)
{
    scene()->removeItem(elements[i+j*width]);
    delete elements[i+j*width];
    elements[i+j*width]=NULL;
    fMatrix[j+i*width] = 0;
}




