#ifndef OBSTACLE_LIST_H
#define OBSTACLE_LIST_H

#include "obstacle_node.h"
#include "Arduino.h"
#include "car.h"

class Obstacle_List
{
public:
    Obstacle_List();
    Obstacle_node *first;
    bool isEmpty();
    void insert(Point);
    void checkObstacles();
    int totalObstacles();
    bool checkCollision(Car);
};

#endif // OBSTACLE_LIST_H
