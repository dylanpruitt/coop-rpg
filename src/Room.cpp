#include "Room.h"
#include "skills/Skill.h"
#include "textGraphics.h"
#include <iostream>

Room::Room ()
{
    //ctor
}

Room::Room (std::vector <Entity*> encounter)
{
    for (int i = 0; i < encounter.size (); i++) {
        this->encounter.push_back (encounter [i]);
    }
}

Room::~Room()
{
    //dtor
}

void Room::event (std::vector <Entity*> players) {
    if (encounter.size () > 0) {
        std::cout << "You encounter monsters!" << std::endl;
        std::cout << encounter [0]->health;
        battle (players);
    }
}

void Room::battle (std::vector <Entity*> players) {
    std::vector <Entity*> combatants;

    for (int i = 0; i < players.size (); i++) { combatants.push_back (players [i]); }
    for (int i = 0; i < encounter.size (); i++) { combatants.push_back (encounter [i]); }

    while (faction_members_remain ("player", combatants) && faction_members_remain ("enemy", combatants)) {
        for (int i = 0; i < players.size (); i++) {
            if (players [i]->is_alive () && faction_members_remain ("enemy", combatants)) {
                players [i]->energy += 3;
                if (players [i]->energy > players [i]->max_energy) {
                    players [i]->energy = players [i]->max_energy;
                }

                std::vector <Status*> remaining_statuses;
                for (int j = 0; j < players [i]->statuses.size (); j++) {
                    players [i]->statuses [j]->turns_left--;

                    if (players [i]->statuses [j]->turns_left > 0) {
                        remaining_statuses.push_back (players [i]->statuses [j]);
                    }
                }
                players [i]->statuses.swap (remaining_statuses);

                std::cout << "\n- - -- ==< " << players [i]->name << "'s turn >== -- - -" << std::endl;
                display_combatant_information (players);
                display_skills (players [i]);

                int skill_index = -1;
                bool looping = true;
                while (looping) {
                    std::cin >> skill_index;
                    if (players [i]->energy >= players [i]->skills [skill_index]->energy_cost) {
                        looping = false;
                    } else {
                        std::cout << "Not enough energy!" << std::endl;
                    }
                }

                players [i]->skills [skill_index]->use (players [i], combatants);

        }
        }

        for (int i = 0; i < encounter.size (); i++) {
            if (encounter [i]->is_alive ()) {
                encounter [i]->energy += 3;
                encounter [i]->AI (combatants);
            }
        }
    }

    if (faction_members_remain ("player", combatants)) {
        std::cout << "You won!" << std::endl;

        int experience_total = 0;
        for (int i = 0; i < encounter.size (); i++) {
            experience_total += encounter [i]->experience;
        }

        for (int i = 0; i < players.size (); i++) {
            players [i]->experience += experience_total;
            players [i]->promote ();
            for (int j = 0; j < players [i]->statuses.size (); j++) {
                players [i]->statuses [j]->on_battle_end (players [i]);
            }
            players [i]->statuses.clear ();
        }
    }
}

bool Room::faction_members_remain (std::string faction, std::vector <Entity*> combatants) {
    bool members_alive = false;

    for (int i = 0; i < combatants.size (); i++) {
        if (combatants [i]->health > 0 && combatants [i]->faction == faction) { members_alive = true; }
    }

    return members_alive;
}

void Room::display_combatant_information (std::vector <Entity*> players) {
    for (int i = 0; i < players.size (); i++) {
        std::cout << players [i]->name << " (Health ";
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << players [i]->health;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " / ";
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << players [i]->max_health;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " Energy ";

        textGraphics::changeTextColor (textGraphics::colors::LIGHT_YELLOW, textGraphics::colors::BLACK); std::cout << players [i]->energy;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " / ";
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_YELLOW, textGraphics::colors::BLACK); std::cout << players [i]->max_energy;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << ")" << std::endl;
    }
    std::cout << "vs." << std::endl;
        for (int i = 0; i < encounter.size (); i++) {
        std::cout << encounter [i]->name << " (Health ";
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << encounter [i]->health;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " / ";
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << encounter [i]->max_health;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << ")" << std::endl;
    }
}

void Room::display_skills (Entity* player) {
    std::cout << "Skills:" << std::endl;

    for (int j = 0; j < player->skills.size (); j++) {
        std::cout << "[";
        textGraphics::changeTextColor (textGraphics::colors::RED, textGraphics::colors::BLACK); std::cout << j;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK);
        std::cout << "] - " << player->skills [j]->name << " (";

        textGraphics::changeTextColor (textGraphics::colors::YELLOW, textGraphics::colors::BLACK);
        std::cout << player->skills [j]->energy_cost;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK);
        std::cout << ") : " << player->skills [j]->description << std::endl;
    }
}
