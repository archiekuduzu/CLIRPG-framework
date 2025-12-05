#pragma once
#include <string>

struct character_attributes
{
        float health = 100.f;
        float ability_points = 100.f;
        float damage = 1.f;
        float armor = 1.f;
};

class character
{
public:
        std::string get_character_name() const { return character_name_; }
        character_attributes get_attributes() const { return attributes_ ;}
private:
        std::string character_name_; 
        character_attributes attributes_;
};