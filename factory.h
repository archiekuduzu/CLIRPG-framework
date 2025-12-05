#include "command.h"
#include "game_state.h"
#include "menu.h"

class MenuFactory
{
public:
        // ------------------ COMMANDS -----------------
        // Main Menu Commands -----------------------
        static command* StartCommand(game_state* game)
        {
                return new command("Start Game", [game]()
                {
                        std::cout << "Starting game...\n";
                        game->app_state = running;

                        std::cout << "\n Please enter your name: ";
                        std::cin >> game->player_name;

                        game->menu_stack.push_back(CreateGameMenu(game));
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
        // Main Menu Commands ---------------------

        // Game Menu Commands ---------------------
        static command* InvestigateAreaCommand(game_state* game)
        {
                return new command("Investigate Area", [game]()
                {
                        std::cout << "Investigating area...\n";
                        // implementation of area investigation goes here
                });
        }

        static command* ShowPartyMenuCommand(game_state* game)
        {
                return new command("Show Party Menu", [game]()
                {
                        std::cout << "Showing party menu...\n";
                        // implementation of showing party menu goes here
                });
        }
        // Game Menu Commands ---------------------
        // ------------------ COMMANDS -----------------

        // ------------------ MENUS --------------------
        static menu* CreateMainMenu(game_state* game)
        {
                menu* main_menu = new menu("Main Menu");
                main_menu->add(StartCommand(game));
                main_menu->add(EndCommand(game));
                // add more commands if needed
                return main_menu;
        }
    
        static menu* CreateGameMenu(game_state* game)
        {
                menu* game_menu = new menu("Game Menu");
                game_menu->add(InvestigateAreaCommand(game));
                game_menu->add(ShowPartyMenuCommand(game));
                // add more commands if needed
                return game_menu;
        }
        // ------------------ MENUS --------------------
};