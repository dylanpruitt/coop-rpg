#include "healRoom.h"
#include <iostream>

healRoom::healRoom()
{
    //ctor
}

healRoom::~healRoom()
{
    //dtor
}

void healRoom::event (std::vector <Entity*> players) {
    for (unsigned int i = 0; i < players.size (); i++) {
        players [i]->health += (players [i]->max_health / 2);
        if (players [i]->health > players [i]->max_health) {
            players [i]->health = players [i]->max_health;
        }
    }

    std::cout << "You stop to rest, and heal some of your wounds." << std::endl;
}
