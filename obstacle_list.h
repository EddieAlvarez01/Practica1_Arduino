#ifndef OBSTACLE_LIST_H
#define OBSTACLE_LIST_H

#include "obstacle_node.h"

class Obstacle_List
{
public:
    Obstacle_List();
    Obstacle_node *first;
    bool isEmpty();
    void insert(Point);
    void checkObstacles();
    int totalObstacles();
};

#endif // OBSTACLE_LIST_H
