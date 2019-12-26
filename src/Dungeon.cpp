#include "Dungeon.h"
#include <iostream>

Dungeon::Dungeon()
{
    //ctor
}

Dungeon::~Dungeon()
{
    //dtor
}

void Dungeon::loop (std::vector <Entity*> players) {
    while (faction_members_remain ("player", players) && room_number < rooms.size ()) {
        rooms [room_number].event (players);
        room_number++;
    }

    if (faction_members_remain ("player", players) && room_number == rooms.size ()) {
        std::cout << "You won!" << std::endl;
    }
}

bool Dungeon::faction_members_remain (std::string faction, std::vector <Entity*> combatants) {
    bool members_alive = false;

    for (int i = 0; i < combatants.size (); i++) {
        if (combatants [i]->health > 0 && combatants [i]->faction == faction) { members_alive = true; }
    }

    return members_alive;
}
