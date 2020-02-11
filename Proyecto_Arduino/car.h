#ifndef CAR_H
#define CAR_H

#include "point.h"

class Car
{
public:
    Car();
    Point p1; //Pata superior izquierda
    Point p2; //Pata superior derecha
    Point p3; //Centro
    Point p4; //Pata inferior izquierda
    Point p5; //Pata inferior derecha
};

#endif // CAR_H
