#include <QGraphicsScene>
#include <QGraphicsView>

#include "Field.h"

extern QGraphicsScene *scene;
extern QGraphicsView *view;

Field::Field(int a, int b, QVector <int> init)
{
    width = a;
    height = b;
    fieldMatrix = init;

    //go through fieldMatrix and in acc with its data fill elements;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (fieldMatrix[i+j*width] == 1)
            {
                elements.push_back(BaseElement::makeElement(wallID, j,i));
                scene->addItem(elements.back());
            }
            else if (fieldMatrix[i+j*width] == 2)
            {
                elements.push_back(BaseElement::makeElement(armoredWallID, j,i));
                scene->addItem(elements.back());
            }
            else if (fieldMatrix[i+j*width] == 3)
            {
                elements.push_back(BaseElement::makeElement(headquartersID, j, i));
                scene->addItem(elements.back());
            } else{
                elements.push_back(NULL);
            }
        }
    }
}

Field::~Field()
{
    for (unsigned int i=0; i < elements.size(); i++ )
    {
        scene->removeItem(elements[i]);
        delete elements[i];
    }
}

int Field::check(int a, int b)
{
    if (fieldMatrix[a+b*width] != 0)
    {
        return 0;
    }
    else
        return 1;
}

void Field::destroy(BaseElement* base)
{
    for(int i = 0 ; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (elements[i+j*width] == base){
                scene->removeItem(elements[i+j*width]);
                delete elements[i+j*width];
                elements[i+j*width]=NULL;
                fieldMatrix[j+i*width] = 0;
            }
        }
    }
}

void Field::destroy(int i, int j)
{
    scene->removeItem(elements[i+j*width]);
    delete elements[i+j*width];
    elements[i+j*width]=NULL;
    fieldMatrix[j+i*width] = 0;
}
