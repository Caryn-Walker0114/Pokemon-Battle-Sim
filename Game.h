#ifndef GAME_H
#define GAME_H

#include "Pokemon.h"

class Game
{
    public:
        Game(); // ctor

        virtual ~Game(); // dtor

        bool retry();

        void playGame();


        //---------Friend Functions-------//

        friend bool fightOn(Pokemon & p, Pokemon & e);

        friend void Battle(Pokemon & p, Pokemon & e);

        friend void printInfo();

    private:
};

#endif // GAME_H






