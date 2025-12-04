#pragma once
#include <iostream>
#include "string"

class command
{
public:
        virtual ~command() = default;
        command(const std::string command_name);
        command(const std::string command_name, const std::string description_text);

        virtual void execute();
        virtual void execute(int i);

        std::string GetName();
        std::string GetDescription();
protected:
        std::string name_;
        std::string description_;
};
