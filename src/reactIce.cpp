#include "reactIce.h"
#include "Entity.h"
#include "textGraphics.h"
#include <iostream>

reactIce::reactIce()
{
    turns_left = 99;
    name = "React:Ice";
}

reactIce::~reactIce()
{
    //dtor
}

void reactIce::on_ice_damage (Entity* parent, std::vector <Entity*> combatants) {
    std::cout << parent->name;
    textGraphics::changeTextColor (textGraphics::colors::LIGHT_AQUA, textGraphics::colors::BLACK); std::cout << " reacted";
    textGraphics::changeTextColor (textGraphics::colors::WHITE, textGraphics::colors::BLACK); std::cout << " to the ice attack!" << std::endl;

    for (int i = 0; i < combatants.size (); i++) {
        if (parent->faction != combatants [i]->faction) {
            parent->damage (combatants [i], 11);
        }
    }
}
