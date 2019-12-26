#include "poisonFungus.h"
#include "Haze.h"
#include <iostream>
#include "textGraphics.h"

poisonFungus::poisonFungus()
{
    name = "Poison Fungus";
    health = 20;
    max_health = 20;

    attack = 0;
    defense = 0;

    experience = 5;
}

poisonFungus::~poisonFungus()
{
    //dtor
}

void poisonFungus::AI (std::vector <Entity*> combatants) {
    std::cout << this->name << " releases";
    textGraphics::changeTextColor (textGraphics::colors::LIGHT_GREEN, textGraphics::colors::BLACK); std::cout << " poisonous";
    textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " spores!" << std::endl;
    for (int i = 0; i < combatants.size (); i++) {
        if (combatants [i]->name != this->name) {
            combatants [i]->statuses.push_back (new Haze ());
        }
    }
}
