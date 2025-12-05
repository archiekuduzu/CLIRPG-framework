#pragma once 
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

                        std::cout << "\nPlease enter your name: ";
                        std::cin >> game->player_name;

                        std::cout << "\nEnter character name: ";
                        game->party.push_back(new character());
                        std::string input;
                        std::cin >> input;
                        game->party.back()->set_character_name(input);
                        game->menu_stack.push_back(CreateGameMenu(game));
                        game->menu_stack.push_back(ClassSelectMenu(game, game->party.at(0)));
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

        static command* RestartGameCommand(game_state* game)
        {
                return new command("Restart Game", [game]
                {
                        char input;
                        std::cout << "Do you want to restart?\n";
                        std::cin >> input;
                        if (input == 'y' || input == 'Y')
                        {
                                std::cout << "Restarting game...\n";
                                game->app_state = restarting;
                        }
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

                        for (auto& p : game->party)
                        {
                                std::cout << p->get_character_name() + " " + getCharacterClassName(p->get_character_class()) + "\n";
                        }
                });
        }

        // party menus
        static command* SelectClassFighterCommand(game_state* game, character* character_)
        {
                return new command("Select Fighter", [game, character_]()
                {
                        character_->set_character_class(Fighter);
                        game->menu_stack.pop_back();
                });
        }

        static command* SelectClassRangerCommand(game_state* game, character* character_)
        {
                return new command("Select Ranger", [game, character_]()
                {
                        character_->set_character_class(Ranger);
                        game->menu_stack.pop_back();
                });
        }

        static command* SelectClassWizardCommand(game_state* game, character* character_)
        {
                return new command("Select Wizard", [game, character_]()
                {
                        character_->set_character_class(Wizard);
                        game->menu_stack.pop_back();
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
                game_menu->add(RestartGameCommand(game));
                // add more commands if needed
                return game_menu;
        }

        static menu* ClassSelectMenu(game_state* game, character* character_)
        {
                menu* class_select_menu = new menu("Class Selection Menu");
                class_select_menu->add(SelectClassFighterCommand(game, character_));
                class_select_menu->add(SelectClassRangerCommand(game, character_));
                class_select_menu->add(SelectClassWizardCommand(game, character_));
                return class_select_menu;
        }
        // ------------------ MENUS --------------------
};