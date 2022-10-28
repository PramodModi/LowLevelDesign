#include <iostream>
# include "Game.cpp"
using namespace std;

int main(){
    int boardSize = 10;
    int numOfDice = 1;
    int snakes= 8;
    int ladders = 7;
    int players = 4;
    Game * game = new Game(boardSize, numOfDice, snakes, ladders, players);
    game->startGame();

    return 1;
}