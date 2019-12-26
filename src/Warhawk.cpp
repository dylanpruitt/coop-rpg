#include "Warhawk.h"
#include "skills/Attack.h"
#include "skills/attackBoost.h"
#include "skills/Ice.h"

Warhawk::Warhawk()
{
    name = "Warhawk";
    health = 70;
    max_health = 70;

    attack = 8;
    defense = 8;

    experience = 60;

    skills.push_back (new Attack ());
    skills.push_back (new Ice ());
    skills.push_back (new attackBoost ());
}

Warhawk::~Warhawk()
{
    //dtor
}

void Warhawk::AI (std::vector <Entity*> combatants) {
    const int ATTACK = 0, ICE = 1, ATTACK_BOOST = 2;
    std::vector <Entity*> targets; int target_index = 0;

    switch (turn_counter) {
        case 1:
            target_index = target_random_enemy (combatants);
            targets.push_back (combatants [target_index]);
            this->skills [ATTACK]->use (this, targets);
            turn_counter++;
            break;
        case 2:
            for (int i = 0; i < combatants.size (); i++) {
                if (combatants [i]->faction != "enemy") {
                    targets.push_back (combatants [i]);
                }
            }

            this->skills [ICE]->use (this, targets);
            turn_counter++;
            break;
        case 3:
            targets.push_back (this);
            this->skills [ATTACK_BOOST]->use (this, targets);
            turn_counter = 1;
            break;
    }
    if (turn_counter == 3) {


        turn_counter = 1;
    } else {
        turn_counter++;
    }
}
