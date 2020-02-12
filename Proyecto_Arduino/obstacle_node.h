#ifndef OBSTACLE_NODE_H
#define OBSTACLE_NODE_H

#include "point.h"

class Obstacle_node
{
public:
    Obstacle_node(Point);
    Point a;
    Obstacle_node *next;
};

#endif // OBSTACLE_NODE_H
