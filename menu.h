#pragma once
#include <vector>
#include <string>
#include "command.h"

class menu
{
public:
        menu(const std::string& title) : title_(title) {}

        void add(command* cmd) 
        {
                command_stack.push_back(cmd);
        }

        std::string get_title()
        {
                return title_;
        }

        void render_menu()
        {
                std::cout << title_ << std::endl;
                std::cout << "-----------------------------" << std::endl;
                for(size_t i = 0; i < command_stack.size(); ++i)
                {
                        std::cout << i+1 << ". " << command_stack[i]->get_name() << std::endl;
                }
                std::cout << "-----------------------------" << std::endl;
        }

        std::vector<command*> get_commands()
        {
                return command_stack;
        };

private:
        std::string title_;
        std::vector<command*> command_stack;
};

class MenuFactory
{
public:
        static menu* CreateMainMenu()
        {
                menu* main_menu = new menu("Main Menu");
                main_menu->add(CommandFactory::StartCommand());
                main_menu->add(CommandFactory::EndCommand());
                // add more commands if needed
                return main_menu;
        }
    
        // create more static functions to initialize other types of menus if needed
};