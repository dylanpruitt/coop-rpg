#include "Entity.h"
#include "textGraphics.h"
#include "skills/Fire.h"
#include "skills/Lightning.h"
#include "skills/Ice.h"
#include <iostream>

Entity::Entity()
{
    //ctor
}

Entity::~Entity()
{
    //dtor
}

bool Entity::is_alive () {
    if (health > 0) {
        return true;
    } else {
        return false;
    }
}

bool Entity::has_status (std::string status_name) {
    for (int i = 0; i < statuses.size (); i++) {
        if (statuses [i]->name == status_name) {
            return true;
        }
    }

    return false;
}

void Entity::remove_status (std::string status_name) {
    for (int i = 0; i < statuses.size (); i++) {
        if (statuses [i]->name == status_name) {
            statuses.erase (statuses.begin () + i);
            return;
        }
    }
}

void Entity::damage (Entity* target, int amount) {
    int damage = amount;

    damage -= target->defense;

    if (target->has_status ("Dodge")) {
        std::cout << target->name;
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_YELLOW, textGraphics::colors::BLACK); std::cout << " dodged ";
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << "the attack!" << std::endl;
        target->remove_status ("Dodge");
    } else {
        if (damage > 0) {
            std::cout << target->name + " took ";
            textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << damage;
            textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " damage!" << std::endl;
            target->health -= damage;
        } else {
            std::cout << target->name + " took no damage." << std::endl;
        }
    }
}

void Entity::promote () {
    if (experience >= level * level * 4) {
        std::cout << name << " has leveled up!" << std::endl;

        max_health += rand () % 3 + 1;
        health = max_health;

        attack++;
        defense++;

        level++;

        if (level == 2) {
            std::vector <Skill*> skill_choices; skill_choices.push_back (new Fire ()); skill_choices.push_back (new Ice ()); skill_choices.push_back (new Lightning ());
            std::cout << name << " can learn a new skill." << std::endl;
            for (int j = 0; j < skill_choices.size (); j++) {
                std::cout << "[";
                textGraphics::changeTextColor (textGraphics::colors::RED, textGraphics::colors::BLACK); std::cout << j;
                textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK);
                std::cout << "] - " << skill_choices [j]->name << " (";

                textGraphics::changeTextColor (textGraphics::colors::YELLOW, textGraphics::colors::BLACK);
                std::cout << skill_choices [j]->energy_cost;
                textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK);
                std::cout << ") : " << skill_choices [j]->description << std::endl;
            }
            int input; std::cin >> input;

            skills.push_back (skill_choices [input]);
        }
    }
}

void Entity::AI (std::vector <Entity*> combatants) {
    textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << "[!] " << name << " AI not implemented!";
    textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK);
}

int Entity::target_lowest_health_enemy (std::vector <Entity*> combatants) {
    int lowest_health_value = 100;
    int target_index = 0;

    for (int i = 0; i < combatants.size (); i++) {
        if (!(combatants [i]->faction == faction)) {
            if (combatants [i]->health < lowest_health_value && combatants [i]->health > 0) {
                lowest_health_value = combatants [i]->health;
                target_index = i;
            }
        }
    }

    return target_index;
}

int Entity::target_highest_health_enemy (std::vector <Entity*> combatants) {
    int highest_health_value = 0;
    int target_index = 0;

    for (int i = 0; i < combatants.size (); i++) {
        if (!(combatants [i]->faction == faction)) {
            if (combatants [i]->health > highest_health_value) {
                highest_health_value = combatants [i]->health;
                target_index = i;
            }
        }
    }

    return target_index;
}

int Entity::target_random_enemy (std::vector <Entity*> combatants) {
    std::vector <int> valid_indices;

    for (int i = 0; i < combatants.size (); i++) {
        if (!(combatants [i]->faction == faction) && combatants [i]->is_alive ()) {
            valid_indices.push_back (i);
        }
    }

    int random_index = rand () % (valid_indices.size () - 1);

    return valid_indices [random_index];
}
