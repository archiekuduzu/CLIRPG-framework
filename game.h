#pragma once
#include "menus.h"

/// game.h
/// this file is where we define global enums and variables for use across the entire application
/// you can think of this file as the "game state" definition

enum application_state
{
        running = 0,
        exiting = 1,
        restarting = 2
};

extern application_state game_state;
extern std::string player_name;
extern std::vector<menu*> menu_stack;