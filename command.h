#pragma once
#include <functional>

#include <string>
#include <cstdlib>

// Function to check if a string is a number
inline bool is_number(const std::string& s)
{
        char* end = nullptr;
        double val = strtod(s.c_str(), &end);
        return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}

// Function to check if a string is NOT a number
inline bool is_not_a_number(const std::string& s)
{
        return !is_number(s);
}

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