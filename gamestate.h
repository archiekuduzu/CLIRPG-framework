#pragma once
#include <vector>

#include "menu.h"

enum application_state
{
        running = 0,
        exiting = 1,
        restarting = 2
};

class game_state
{
public:
        application_state app_state = restarting;
        std::string player_name;
        std::vector<menu*> menu_stack;

        game_state();
        ~game_state();
};