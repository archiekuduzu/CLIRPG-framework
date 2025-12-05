// CLIRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <complex>
#include <iostream>
#include "game_state.h"
#include "command.h"
#include "menu.h"
#include "factory.h"

int main()
{
       game_state* game = new game_state();

       while (game->app_state != exiting)
       {
              if (game->app_state == restarting)
              {
                     delete game;
                     game = new game_state();
                     std::cout << "Starting Game...\n";
                     game->menu_stack.push_back(MenuFactory::CreateMainMenu(game));
              }

              game->menu_stack.back()->render_menu();
              std::cout << "Please input choice: ";
              std::string input_string = " ";
              while (is_not_a_number(input_string))
              {
                     std::cin >> input_string;
                     if (is_number(input_string))
                     {
                            int input = std::stoi(input_string); // decrement because zero indexed
                            input--;
                            std::cout << "\n";
                            if (game->menu_stack.size() >= input)
                            {
                                   game->menu_stack.back()->get_commands().at(input)->execute();
                            }
                            else std::cout << "Invalid input!\n";
                     }
                     else
                     {
                            std::cout << "Bad input! Try again!\n";
                     }
              }
       }

       delete game;
       game = nullptr;
       return 0;
}
