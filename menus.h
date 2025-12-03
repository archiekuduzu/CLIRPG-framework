#pragma once

#include "menu.h"
// Menus
class main_menu : public menu
{
public:
        main_menu();
};

// Commands
class start_game_cmd : public command
{
public:
        start_game_cmd();
        void execute() override;
};

class end_game_cmd : public command
{
public:
        end_game_cmd();
        void execute() override;
};

class back_cmd : public command
{
public:
        back_cmd();
        void execute() override;
};

class investigate_cmd : public command
{
public:
        investigate_cmd();
        void execute() override;
};

/// Commands
class game_menu : public menu
{
public:
        game_menu();
};