#include "menu.h"

menu::menu(std::string menu_title) : title_(menu_title) {
}

void menu::add(command* item) {
	command_list_.push_back(item);
}

void menu::remove(command* item) {
	command_list_.erase(std::remove(command_list_.begin(), command_list_.end(), item), command_list_.end());
}

void menu::render_menu() {
	std::cout << title_ << "\n";
	for (std::size_t i = 0; i < command_list_.size(); ++i) {
		std::cout << (i+1) << ": " << command_list_[i]->GetName() << "\n";
	}
}

std::size_t menu::size()
{
	return command_list_.size();
}

command* menu::get_command_by_index_(std::size_t i)
{
	return command_list_[i];
}
