#include <QDebug>
#include <QTimer>

#include "Game.h"
#include "Tanks/TankFactory.h"
#include "Field/BaseElement.h"

PlayerTank *Game::getPlayer()
{
    return player;
}

Game::Game(QWidget *parent)
{
    //create a scene
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create player
    player = (PlayerTank*)TankFactory::makeTank(PlayerID);
    qDebug() << "player created";
    player->setRect(0, 0, 50, 50);
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    qDebug() << "Focus is on player";


    //create enemy
    enemy = (EnemyTank*) TankFactory::makeTank(EnemyID);
    qDebug() << "Enemy created";
    enemy->setRect(0,0,50,50);
    enemies.push_back(enemy);
    scene->addItem(enemy);
    enemy->setPos(450, 250);

    //create wall
    wall = (Wall*)BaseElement::makeElement(wallID,10,10);
    qDebug() << "Wall created";
    wall->setRect(0,0,50,50);
    scene->addItem(wall);

}


