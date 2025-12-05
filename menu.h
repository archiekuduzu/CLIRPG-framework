#pragma once
#include <iostream>
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
                std::cout << "\n" << title_ << "\n";
                std::cout << "-----------------------------" << "\n";
                for(size_t i = 0; i < command_stack.size(); ++i)
                {
                        std::cout << i+1 << ". " << command_stack[i]->get_name() << "\n";
                }
                std::cout << "-----------------------------" << "\n\n";
        }

        std::vector<command*> get_commands()
        {
                return command_stack;
        };

private:
        std::string title_;
        std::vector<command*> command_stack;
};