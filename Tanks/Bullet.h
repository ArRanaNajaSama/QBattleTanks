#pragma once

#include <QObject>
#include <QGraphicsRectItem>

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Bullet(int newBDirection);

public slots:
    void move();

private:
    int bDirection;
};
