// CLIRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "menus.h"
#include "game.h"

application_state game_state = restarting;
std::string player_name;
std::vector<menu*> menu_stack;

menu *create_main_menu()
{
    menu *main_menu = new class main_menu();

    return main_menu;
}

// this is the opening sequence of the game where we set the global playername variable.
void opening_sequence()
{
    std::cout << "CLIRPG\n";
    std::cout << "Text based RPG adventure\n";
    std::cout << "Please enter your name: ";
    std::cin >> player_name;
    std::cout << "Welcome " + player_name + "!\n";
    menu_stack.push_back(create_main_menu()); 
    return;
}

int main()
{    
    while (game_state != exiting)
    {
        // if we are restarting, just clear the menu stack and run the opening sequence.
        if (game_state == restarting)
        {
            menu_stack.clear();
            opening_sequence();
            game_state = running;
        }
        
        menu_stack.back()->render_menu();
        std::cout << "Please Input your choice: ";
        std::size_t choice;
        std::cin >> choice;
        choice--;

        if (choice > menu_stack.back()->size())
            return 0;
        else
            menu_stack.back()->get_command_by_index_(choice)->execute();
    }
    
    return 0;
}
