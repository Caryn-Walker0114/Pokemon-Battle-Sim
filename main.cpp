#include "Game.h"
#include "Pokemon.h"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include <ctime>


//----------MAIN FUNCTION HERE-------------------------

int main()
{
    Game game;
    do{game.playGame(); }
    while(game.retry() == true);

    return 0;
}

