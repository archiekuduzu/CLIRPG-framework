#pragma once
#include <functional>
#include <iostream>

class command
{
public:
        command(const std::string& n, std::function<void()> f) : name_(n), func(f) {}

        //...

        void execute() 
        { 
                func(); 
        }

        std::string get_name()
        {
                return name_;
        }

protected:
        std::string name_;
        std::function<void()> func;
        //...
};

class CommandFactory
{
public:
        static command* StartCommand()
        {
                return new command("Start Game", [](){std::cout << "Starting game...\n";});
        }

        static command* EndCommand()
        {
                return new command("End Game", [](){std::cout << "Ending game...\n";});
        }
};