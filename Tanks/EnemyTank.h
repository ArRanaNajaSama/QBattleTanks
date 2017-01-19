#pragma once

#include <QTimer>

#include "BaseTank.h"

class EnemyTank : public BaseTank
{
    Q_OBJECT

public:
    explicit EnemyTank();
    explicit EnemyTank(int a, int b);
    ~EnemyTank();

public slots:
    void launch();

private:
    QTimer *eTimer;

};

