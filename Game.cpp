#include "Game.h"
#include "Pokemon.h"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include <ctime>

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

//------------------------------------GAME FUNCTION----------------------------------------

bool Game::retry()
{
  static bool tryAgain;
  char yes_no;
  std::cout << "Do you want to play again? Y/N \n";

  do //So I still need to create a way to prevent more than one character from being accepted (you), (no), etc as these will pass the test even though yes_no is a char...
  {
    std::cin >> yes_no;

    if(yes_no == 'Y' || yes_no == 'y')
    {
      std::cout << "Restarting game...\n\n";

      tryAgain = true;
    }


    else if(yes_no == 'N' || yes_no == 'n')
    {
      std::cout << "Thanks for playing!\n";
      std::cout << "Terminating...\n\n";

      tryAgain = false;
    }


    else if(!(yes_no))
    {
      std::cout << "Let's see if this ever happens...\n";
    }

    else
    {
      std::cout << "Invalid input. Please try again. \n";

      std::cin.clear();
      std::cin.ignore(10000, '\n');

      retry();
    }

    return tryAgain;

  }while(!(yes_no));


} //---- bool retry() end brace



//------------------------------------

bool fightOn(Pokemon & p, Pokemon & e) //Friend function
{
    bool fight;


    if(e.getHealth() > 0 && p.getHealth() > 0)
    { fight = true; }


    else { fight = false;}


    return fight;
}


//-------------

void Battle(Pokemon & p, Pokemon & e)  //Friend function
{

      //speed check: whoever is faster goes first
      //pokemon attacks other pokemon, new health = old health - attack
      //health check: if other pokemon is still alive, it attacks
      //pokemon attacks other pokemon, new health = old health - attack
      //final health check, if both pokemon are still alive bool value will return true
      //if one pokemon is fainted, bool value will return false and do..while will exit


    if(p.getSpeed() > e.getSpeed()) // SPEED CHECK -- Make following code a separate function
    {
        p.playerTurn(p, e);


        if(e.getHealth() > 0) // HEALTH CHECK --- Make following code a separate function
        {
            e.enemyTurn(p, e);
        }

        else if(e.getHealth() <= 0)
        {
            std::cout << "The enemy has run out of health! You win!\n\n";
        }

    }



      else if(e.getSpeed() > p.getSpeed()) // SPEED CHECK -- Make following code a separate function
      {
        e.enemyTurn(p, e);

        if(p.getHealth() > 0) //HEALTH CHECK --Make following code a separate function
        {
                p.playerTurn(p, e);
        }

        else if(p.getHealth() <= 0)
        {
          std::cout << "Your Pokemon has run out of health! You lose....\n\n";
          std::cout << "Game Over...\n\n";
        }

      }



      else //Make a random function to decide who goes first
      {
        int tieBreaker;
        std::mt19937 whoGoesFirst(time(0));

        std::uniform_int_distribution<int> dist(1,2);

            tieBreaker = dist(whoGoesFirst);

        if(tieBreaker == 1)//PLAYER TURN CODE HERE
        {
          p.playerTurn(p, e);

          if(e.getHealth() > 0) // HEALTH CHECK --- Make following code a separate function
          {
            e.enemyTurn(p, e);
          }

            else if(e.getHealth() <= 0)
          {
            std::cout << "The enemy has run out of health! You win!\n\n";
          }
        }

        else if(tieBreaker == 2)//ENEMY TURN CODE HERE
        {
                e.enemyTurn(p, e);

          if(p.getHealth() > 0) //HEALTH CHECK --Make following code a separate function
            {
                    p.playerTurn(p, e);
            }

          else if(p.getHealth() <= 0)
          {
            std::cout << "Your Pokemon has run out of health! You lose....\n\n";
            std::cout << "Game Over...\n\n";
          }

        }

      }//Ending else brace

    }//----void Battle() end brace

//--------------


void printInfo(Pokemon p, Pokemon e)  //Friend function
{
  std::cout << "The player's Pokemon is " << p.getName() << "! \n";
  std::cout << p.getHealth() << std::endl;
  std::cout << p.getAttack() << std::endl;
  std::cout << p.getSpeed() << "\n\n";


  std::cout << "The enemy's Pokemon is " << e.getName() << "! \n";
  std::cout << e.getHealth() << std::endl;
  std::cout << e.getAttack() << std::endl;
  std::cout << e.getSpeed() << "\n\n";

}

//--------------

void Game::playGame()
{

//-----------Player stats----------|

  Pokemon playerPokemon;
  playerPokemon.setName();
  playerPokemon.setHealth();
  playerPokemon.setAttack();
  playerPokemon.setSpeed();
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));


//---------------Enemy stats-----------|

  Pokemon enemyPokemon;
  enemyPokemon.setName();
  enemyPokemon.setHealth();
  enemyPokemon.setAttack();
  enemyPokemon.setSpeed();


  //-------------------------------------|

  printInfo(playerPokemon, enemyPokemon);

  do{ Battle(playerPokemon, enemyPokemon) ;}
  while(fightOn(playerPokemon, enemyPokemon) == true);


} //void Game::playGame() end brace


