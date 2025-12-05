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

        std::vector<command*> get_command_stack()
        {
                return command_stack;
        };

private:
        std::string title_;
        std::vector<command*> command_stack;
};