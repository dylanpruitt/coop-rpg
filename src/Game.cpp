#include "Game.h"
#include "skills/Skill.h"
#include "skills/Attack.h"
#include "skills/Ice.h"
#include "skills/attackBoost.h"
#include "skills/dodgeSkill.h"
#include "textGraphics.h"
#include "demoDungeon.h"
#include "skills/Pass.h"
#include <iostream>

Game::Game()
{
    std::cout << "How many players are there? (2 - 3)" << std::endl;
    int number_of_players = 0;
    std::cin >> number_of_players; if (number_of_players < 2 || number_of_players > 3) { number_of_players = 2; }

    for (int i = 0; i < number_of_players; i++) {
        create_player ();
    }

    dungeon = demoDungeon ();
}

Game::~Game()
{
    //dtor
}

void Game::loop () {
    dungeon.loop (players);
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
