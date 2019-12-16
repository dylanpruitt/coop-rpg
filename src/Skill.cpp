#include "Skill.h"
#include <iostream>

Skill::Skill()
{
    //ctor
}

Skill::~Skill()
{
    //dtor
}

void Skill::use (Entity* user, std::vector <Entity*> targets) {
    std::cout << user->name << " used " << name << "!" << std::endl;
    user->energy -= energy_cost;
}

std::vector <Entity*> Skill::find_targets (std::vector <Entity*> combatants, int number_of_targets) {
    std::vector <Entity*> targets;
    std::vector <int> valid_target_indices;

    for (int j = 0; j < combatants.size (); j++) {
        if (combatants [j]->is_alive ()) {
            valid_target_indices.push_back (j);
        }
    }

    while (targets.size () < number_of_targets) {
        int target_index = get_player_target (combatants);
        targets.push_back (combatants [target_index]);
    }

    return targets;
}

int Skill::get_player_target (std::vector <Entity*> combatants) {
    std::vector <int> valid_target_indices;
    int target_index = 0;

    for (int j = 0; j < combatants.size (); j++) {
        if (combatants [j]->is_alive ()) {
            valid_target_indices.push_back (j);
        }
    }

    if (valid_target_indices.size () > 1) {
        std::cout << "Choose a target:" << std::endl;
        for (int j = 0; j < valid_target_indices.size (); j++) {
            std::cout << "[";
            textGraphics::changeTextColor (textGraphics::colors::RED, textGraphics::colors::BLACK); std::cout << j;
            textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK);
            std::cout << "] - " << combatants [valid_target_indices [j]]->name << " (";
            textGraphics::changeTextColor (textGraphics::colors::AQUA, textGraphics::colors::BLACK); std::cout << combatants [valid_target_indices [j]]->health;
            textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " HP)" << std::endl;
        }

        std::cin >> target_index;
    }

    return valid_target_indices [target_index];
}