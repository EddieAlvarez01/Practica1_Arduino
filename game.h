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
    int field [r][c] = {0};
    int figure[4] = {0, 1, 2, 3};
    float timer = 0;
    float delay = 0.3;
    long clock = 0;
    void printBoard();
    void generateObstacle();
    Obstacle_List obstacleList;
};

#endif // GAME_H
