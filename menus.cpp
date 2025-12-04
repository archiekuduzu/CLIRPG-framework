#include "menus.h"
#include "game.h"

// commands
// start game
start_game_cmd::start_game_cmd() : command("Start Game") {}


void start_game_cmd::execute()
{
        std::cout << "This is the start game\n";
        menu_stack.push_back(new game_menu);
        command::execute();
}
// start game

back_cmd::back_cmd() : command("Back")
{
}

void back_cmd::execute()
{
        std::cout << "Back to previous menu...\n";
        menu_stack.pop_back();
        command::execute();
}

// End Game
end_game_cmd::end_game_cmd() : command("End Game") {}


void end_game_cmd::execute()
{
        std::cout << "This is the end of the game\n";
        game_state = exiting;
        command::execute();
}
// endgame

// Investigate Command
investigate_cmd::investigate_cmd() : command("Investigate World")
{
        
}

investigate_cmd::investigate_cmd(const std::string description) : command("Investigate World", description)
{
        description_ = description;
}

void investigate_cmd::execute()
{
        for(int i = 0; i < 5; i++) std::cout << "\n";
        std::cout << "You begin to investigate...\n";
        std::cout << description_ + "\n";
        command::execute();
}


///commands

// menus
// game menu
game_menu::game_menu() : menu("Game Menu")
{
        this->add(new investigate_cmd("This is description text"));
        this->add(new back_cmd());
}

main_menu::main_menu() : menu("Main Menu")
{
        this->add(new start_game_cmd());
        this->add(new end_game_cmd());
}
///menus