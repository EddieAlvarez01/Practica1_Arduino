#include "game.h"

Game::Game()
{

}

void Game::printBoard(){
    for(int x=0; x<16; x++){
        //std::cout << "---------------------------------------------------------------------------------------------------------------------------------\n";
        for(int y=0; y<8; y++){
            //std::cout << "|\t" + std::string((field[x][y] != 0) ? "1" : " ")  + "\t";
        }
        //std::cout << "|\n";
        if(x == 15){
            //std::cout << "---------------------------------------------------------------------------------------------------------------------------------\n";
        }
    }
}

void Game::generateObstacle(){
    int posX = random(0, 8);
    if(posX > 7){
        posX = 7;
    }
    Point a;
    a.x = posX;
    a.y = 0;
    obstacleList.insert(a);
}
