#include "BaseElement.h"

#define cell 50

class Headquarters : public BaseElement
{
public:
    Headquarters(int a, int b);

protected:
    int x;
    int y;
};
