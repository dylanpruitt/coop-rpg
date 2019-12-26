#include "Game.h"
#include "Skill.h"
#include "Attack.h"
#include "attackBoost.h"
#include "dodgeSkill.h"
#include "textGraphics.h"
#include "Rat.h"
#include "lightningBug.h"
#include "Pass.h"
#include <iostream>

Game::Game()
{
    std::cout << "How many players are there? (2 - 3)" << std::endl;
    int number_of_players = 0;
    std::cin >> number_of_players; if (number_of_players < 2 || number_of_players > 3) { number_of_players = 2; }

    for (int i = 0; i < number_of_players; i++) {
        create_player ();
    }
}

Game::~Game()
{
    //dtor
}

void Game::loop () {
    while (faction_members_remain ("player", players)) {
        std::vector <Entity*> enemies;
        enemies.push_back (new Rat ());
        enemies.push_back (new Rat ());
        enemies.push_back (new Rat ());
        enemies.push_back (new lightningBug ());
        battle (enemies);
        enemies.clear ();
    }
}

void Game::battle (std::vector <Entity*> enemies) {
    std::vector <Entity*> combatants;

    for (int i = 0; i < players.size (); i++) { combatants.push_back (players [i]); }
    for (int i = 0; i < enemies.size (); i++) { combatants.push_back (enemies [i]); }

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
                display_combatant_information (enemies);
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

        for (int i = 0; i < enemies.size (); i++) {
            if (enemies [i]->is_alive ()) {
                enemies [i]->energy += 3;
                enemies [i]->AI (combatants);
            }
        }
    }

    if (faction_members_remain ("player", combatants)) {
        std::cout << "You won!" << std::endl;

        int experience_total = 0;
        for (int i = 0; i < enemies.size (); i++) {
            experience_total += enemies [i]->experience;
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

bool Game::faction_members_remain (std::string faction, std::vector <Entity*> combatants) {
    bool members_alive = false;

    for (int i = 0; i < combatants.size (); i++) {
        if (combatants [i]->health > 0 && combatants [i]->faction == faction) { members_alive = true; }
    }

    return members_alive;
}

void Game::display_combatant_information (std::vector <Entity*> enemies) {
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
        for (int i = 0; i < enemies.size (); i++) {
        std::cout << enemies [i]->name << " (Health ";
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << enemies [i]->health;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " / ";
        textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << enemies [i]->max_health;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << ")" << std::endl;
    }
}

void Game::display_skills (Entity* player) {
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

void Game::create_player () {
    Entity* player = new Entity ();
    std::cout << "Enter player " << players.size () + 1 << "'s name: ";
    std::cin >> player->name;
    player->faction = "player";

    player->health = 14;
    player->max_health = 14;
    player->energy = 10;
    player->max_energy = 10;
    player->attack = 2;
    player->defense = 0;

    player->skills.push_back (new Attack ());
    player->skills.push_back (new Pass ());
    player->skills.push_back (new attackBoost ());
    player->skills.push_back (new dodgeSkill ());

    players.push_back (player);
}
