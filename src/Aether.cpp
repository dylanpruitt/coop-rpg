#include "Aether.h"
#include "skills/Ice.h"
#include "reactIce.h"

Aether::Aether()
{
    name = "Aether";
    health = 18;
    max_health = 18;

    attack = 1;
    defense = 4;

    experience = 6;

    skills.push_back (new Ice ());

    statuses.push_back (new reactIce ());
}

Aether::~Aether()
{
    //dtor
}

void Aether::AI (std::vector <Entity*> combatants) {
    const int ICE = 0;

    if (turn_counter == 3) {
        std::vector <Entity*> targets;

        for (int i = 0; i < combatants.size (); i++) {
            if (combatants [i]->faction != "enemy") {
                targets.push_back (combatants [i]);
            }
        }

        this->skills [ICE]->use (this, targets);
        turn_counter = 1;
    } else {
        turn_counter++;
    }
}
