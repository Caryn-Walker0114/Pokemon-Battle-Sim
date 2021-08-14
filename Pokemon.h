#ifndef POKEMON_H
#define POKEMON_H

#include <string>


class Pokemon
{
    public:

        Pokemon(); //Constructor

        //---------Setters--------//

        void setName(); //Have to make it so the names are set inside of the function itself

        int setHealth();

        int battleHealth(int h);


        int setAttack();

        int setSpeed();


        //---------Battle Functions-----------//


        void playerTurn(Pokemon & p, Pokemon & e);

        void enemyTurn(Pokemon & p, Pokemon & e);

        void printInfo(Pokemon p, Pokemon e);


        //-------------Accessors-------------//

        inline const std::string& getName() const { return this->name;}

        inline const int& getHealth() const { return this->health;}

        inline const int& getAttack() const { return this->attack;}

        inline const int& getSpeed() const { return this->speed;}


    private:
        std::string name;
        int health;
        int attack;
        int speed;

};

#endif // POKEMON_H





