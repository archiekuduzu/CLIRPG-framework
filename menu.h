#pragma once

#include <iostream>
#include "string"
#include <vector>
#include "command.h"

class menu
{
public:
	menu(std::string menu_title);

	void add(command *item);
	void remove(command *item);

	void render_menu();
	std::size_t size();
	command* get_command_by_index_(std::size_t i);
protected:
	std::string title_;

	std::vector<command*> command_list_;
};