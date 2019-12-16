#include "Game.h"
#include "Skill.h"
#include "Attack.h"
#include "dodgeSkill.h"
#include "textGraphics.h"
#include <iostream>

Game::Game()
{
    std::cout << "How many players are there? (1 - 4)" << std::endl;
    int number_of_players = 0;
    std::cin >> number_of_players; if (number_of_players < 1 || number_of_players > 4) { number_of_players = 2; }

    for (int i = 0; i < number_of_players; i++) {
        create_player ();
    }
}

Game::~Game()
{
    //dtor
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
                display_player_information (players [i]);

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
    }
}

bool Game::faction_members_remain (std::string faction, std::vector <Entity*> combatants) {
    bool members_alive = false;

    for (int i = 0; i < combatants.size (); i++) {
        if (combatants [i]->health > 0 && combatants [i]->faction == faction) { members_alive = true; }
    }

    return members_alive;
}

void Game::display_player_information (Entity* player) {
    std::cout << "Health (";
    textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << player->health;
    textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " / ";
    textGraphics::changeTextColor (textGraphics::colors::LIGHT_RED, textGraphics::colors::BLACK); std::cout << player->max_health;
    textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << ")" << std::endl;

    std::cout << "Energy (";
    textGraphics::changeTextColor (textGraphics::colors::LIGHT_YELLOW, textGraphics::colors::BLACK); std::cout << player->energy;
    textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " / ";
    textGraphics::changeTextColor (textGraphics::colors::LIGHT_YELLOW, textGraphics::colors::BLACK); std::cout << player->max_energy;
    textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << ")" << std::endl;

    std::cout << "Skills:" << std::endl;

    for (int j = 0; j < player->skills.size (); j++) {
        std::cout << "[";
        textGraphics::changeTextColor (textGraphics::colors::RED, textGraphics::colors::BLACK); std::cout << j;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK);
        std::cout << "] - " << player->skills [j]->name << " (";

        textGraphics::changeTextColor (textGraphics::colors::YELLOW, textGraphics::colors::BLACK);
        std::cout << player->skills [j]->energy_cost;
        textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << ")" << std::endl;
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
    player->defense = 2;

    player->skills.push_back (new Attack ());
    player->skills.push_back (new dodgeSkill ());

    players.push_back (player);
}
