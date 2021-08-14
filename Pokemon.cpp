#include "Pokemon.h"
#include "Game.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <ctime>
#include <stdlib.h>


//-------

Pokemon::Pokemon(){} //Ctor


//---------------------Determine Names----------------------


void Pokemon::setName()
{
  int lower = 1;
  int upper = 3;
  int choice;
  std::string pokeName;

  srand (time(NULL) );
  choice = (rand() % (upper - lower + 1)) + lower;

  if(choice == 1)
  {
    pokeName = "Charmander";
  }


  else if(choice == 2)
  {
    pokeName = "Bulbasaur";
  }


  else if(choice == 3)
  {
    pokeName = "Squirtle";
  }


  else
  {
    std::cout << "Invalid choice. Please choose again. \n";// Randomly chosen......So this should never run
    setName();
  }

  std::cout << std::endl;

  name = pokeName;

}


//--------------------Battle Health-----------------------


int Pokemon::battleHealth(int h)
{
    int hStat = h;
    health = hStat;

    return hStat;
}


//-------------------------   POKEMON SET STAT FUNCTIONS   ---------------------------


int Pokemon::setHealth()
{
    int hStat = 0;

    int lower = 25;
    int upper = 28;

    srand (time(0));
    hStat = (rand() % (upper - lower + 1)) + lower;

    health = hStat;

    return hStat;
}

//-------------------


int Pokemon::setAttack()
{
    int aStat = 0;

    int lower = 5;
    int upper = 7;

    srand (time(0));
    aStat = (rand() % (upper - lower + 1)) + lower;

    attack = aStat;

    return aStat;
}


 //-------------------

int Pokemon::setSpeed()
{
    int spdStat = 0;

    int lower = 4;
    int upper = 6;

    srand (time(0));
    spdStat = (rand() % (upper - lower + 1)) + lower;

    speed = spdStat;

    return spdStat;
}


//---------Battle Functions-----------//


void Pokemon::playerTurn(Pokemon & p, Pokemon & e)
{
    std::cout << "Player's Turn! \n\n";

    std::cout << p.getName() << " attacked " << e.getName() << "! \n";
    std::cout << e.getName() << " took " << p.getAttack() << " damage! \n";

    e.battleHealth(e.getHealth() - p.getAttack());

    if(e.getHealth() <= 0)
    {
        std::cout << "The enemy has 0 health left! \n\n";
    }

    else
    {
        std::cout << "The enemy has " << e.getHealth() << " health left! \n\n";
    }


    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}


    //-----------------------------------------------


void Pokemon::enemyTurn(Pokemon & p, Pokemon & e)
{
    std::cout << "Enemy's Turn! \n\n";

    std::cout << e.getName() << " attacked " << p.getName() << "! \n";
    std::cout << p.getName() << " took " << e.getAttack() << " damage! \n";

    p.battleHealth(p.getHealth() - e.getAttack());

    if(p.getHealth() <= 0)
    {
        std::cout << "Your Pokemon has 0 health left! \n\n";
    }

    else
    {
        std::cout << "Your Pokemon has " << p.getHealth() << " health left! \n\n";
    }


    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}

