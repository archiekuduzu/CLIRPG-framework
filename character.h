#pragma once
#include <string>

struct character_attributes
{
        float health = 100.f;
        float ability_points = 100.f;
        float damage = 1.f;
        float armor = 1.f;
};

enum character_class
{
        Fighter = 0,
        Ranger = 1,
        Wizard = 2
};

inline std::string getCharacterClassName(character_class cc) {
        switch(cc) {
        case Fighter:
                return "Fighter";
        case Ranger:
                return "Ranger";
        case Wizard:
                return "Wizard";
                // Add your other classes here
        default:
                return "Unknown";
        }
}

class character
{
public:
        std::string get_character_name() const { return character_name_; }
        std::string set_character_name(std::string name) { character_name_ = name; return character_name_; }
        character_class get_character_class() const { return class_; }
        character_class set_character_class(character_class new_class) { class_ = new_class; return class_ ; }
        character_attributes get_attributes() const { return attributes_; }
private:
        std::string character_name_;
        character_class class_ = Fighter;
        character_attributes attributes_;
};