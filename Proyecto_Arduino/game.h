#ifndef GAME_H
#define GAME_H

#include "Arduino.h"
#include "point.h"
#include "obstacle_list.h"

const int r = 16;
const int c = 8;

class Game
{
public:
    Game();
    void printBoard();
    void generateObstacle();
    Obstacle_List obstacleList;
};

#endif // GAME_H
