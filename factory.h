#include "command.h"
#include "game_state.h"
#include "menu.h"

class CommandFactory
{
public:
        static command* StartCommand(game_state* game)
        {
                return new command("Start Game", [game]()
                {
                        std::cout << "Starting game...\n";
                });
        }

        static command* EndCommand(game_state* game)
        {
                return new command("End Game", [game]()
                {
                        std::cout << "Ending game...\n";
                        game->app_state = exiting;
                });
        }
};

class MenuFactory
{
public:
        static menu* CreateMainMenu(game_state* game)
        {
                menu* main_menu = new menu("Main Menu");
                main_menu->add(CommandFactory::StartCommand(game));
                main_menu->add(CommandFactory::EndCommand(game));
                // add more commands if needed
                return main_menu;
        }
    
        // create more static functions to initialize other types of menus if needed
};
