#include "command.h"

command::command(const std::string command_name)
{
	name_ = command_name;
}

void command::execute()
{
	return;
}

std::string command::GetName()
{
	return name_;
}
