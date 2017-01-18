#pragma once

#include <QVector>
#include <QObject>

#include "BaseElement.h"

class Field : public QObject
{
    Q_OBJECT
public:
    Field(int, int, QVector<int>);
    ~Field();
    int check(int, int);
    void destroy(BaseElement*);
    void destroy(int, int);

signals:
    void objectDelete();

private:
    QVector <BaseElement*> elements;
    QVector <int> fieldMatrix;
    int width;
    int height;

};
