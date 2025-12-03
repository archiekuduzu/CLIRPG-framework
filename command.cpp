#include "command.h"

command::command(const std::string command_name, const std::string description_text)
{
	name_ = command_name;
	description_ = description_text;
}

command::command(const std::string command_name)
{
	name_ = command_name;
	description_ = "";
}

void command::execute()
{
	return;
}

std::string command::GetName()
{
	return name_;
}

std::string command::GetDescription()
{
	return description_;
}
