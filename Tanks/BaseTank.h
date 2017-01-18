#pragma once
#include <QObject>
#include <QGraphicsRectItem>

#include "Bullet.h"
#include "PreMotion.h"

class PreMotion;

class BaseTank:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit BaseTank();
    explicit BaseTank(int a, int b);
    virtual ~BaseTank();

    int getDirection() const;
    void setDirection(int newDirection);

    //rotate tank
    void setTankRotation(int newDirection);

    //common actions for all tanks
    void shot();
    void move(int newDirection);

    // Return type cell
    int checkPosition();

public slots:
    void setMotion(PreMotion *newMotion);

protected:
    int direction;
    qreal speed;
    PreMotion *premotion;

};
