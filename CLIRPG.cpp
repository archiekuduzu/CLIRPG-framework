// CLIRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <complex>
#include <iostream>
#include "gamestate.h"
#include "command.h"

int main()
{
       game_state* game = new game_state();

       while (game->app_state != exiting)
       {
              if (game->app_state == restarting)
              {
                     delete game;
                     game = new game_state();
                     game->app_state = running;
                     std::cout << "Starting Game...\n";
                     game->menu_stack.push_back(MenuFactory::CreateMainMenu());
              }

              game->menu_stack.back()->render_menu();
              std::cout << "Please input choice: ";
              int input;
              std::cin >> input;

              game->menu_stack.back()->get_commands().at(input-1)->execute();
       }

       delete game;
       game = nullptr;
       return 0;
}
