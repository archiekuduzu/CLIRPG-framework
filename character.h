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
        fighter,
        ranger,
        wizard,
        thief,
        class_count
};

inline std::string getCharacterClassName(character_class cc) {
        switch(cc) {
        case fighter:
                return "Fighter";
        case ranger:
                return "Ranger";
        case wizard:
                return "Wizard";
        case thief:
                return "Thief";
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
        character_class class_ = fighter;
        character_attributes attributes_;
};