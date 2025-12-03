#pragma once
#include <iostream>
#include "string"

class command
{
public:
        virtual ~command() = default;
        command(const std::string command_name);

        virtual void execute();

        std::string GetName();
protected:
        std::string name_;
};
