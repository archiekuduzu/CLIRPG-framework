// CLIRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "game.h"
#include "command.h"

application_state game_state = restarting;
std::string player_name;
std::vector<menu*> menu_stack;

void clear_memory()
{
    for(auto& m : menu_stack)
    {
        // Assuming each menu has a `get_commands` or similar method to access the commands
        for(auto& cmd : m->get_command_stack())
        {
            delete cmd;
            cmd = nullptr; // Optional: robustness against double deletion
        }
       
        // Once all commands of a menu have been dealt with, we can delete the menu itself
        delete m;
        m = nullptr; // Optional: robustness against double deletion
    }

    // Clear the menu_stack vector
    menu_stack.clear();
}

int main()
{    
    while (game_state != exiting)
    {
        // if we are restarting, just clear the menu stack and run the opening sequence.
        if (game_state == restarting)
        {
            menu* main_menu = new menu("Main Menu");
            command* begin_game_cmd = new command("Begin Game",[&]
            {
                std::cout << "Beginning game...\n";

                game_state = running;

                std::cout << "Please input your name: ";
                std::cin >> player_name;
                std::cout << "\nWelcome " + player_name + "\n";
            });
            main_menu->add(begin_game_cmd);
            
            command* end_game_cmd = new command("End Game", [&]()
            { 
                std::cout << "Ending game...\n";
                
                // Fix 3: Capture game_state by reference 
                game_state = exiting; 
            });
            main_menu->add(end_game_cmd);
            
            menu_stack.push_back(main_menu);

            
        }
        menu_stack.back()->render_menu();

        std::cout << "Input: ";
        int i;
        std::cin >> i;
        std::cout << "\n";

        menu_stack.back()->get_command_stack().at(i-1)->execute();
    }

    clear_memory();
    
    std::cout << "Exit";
    return 0;
}
