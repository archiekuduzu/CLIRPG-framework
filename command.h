#pragma once
#include <functional>


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