#include "Rat.h"
#include "skills/Attack.h"
#include "skills/attackBoost.h"
#include <iostream>

Rat::Rat()
{
    name = "Rat";
    health = 6;
    max_health = 6;

    attack = 2;
    defense = 0;

    experience = 2;

    skills.push_back (new Attack ());
    skills.push_back (new attackBoost ());
}

Rat::~Rat()
{
    //dtor
}

void Rat::AI (std::vector <Entity*> combatants) {
    const int ATTACK = 0, BOOST_ATTACK = 1;

    int target_index = target_random_enemy (combatants);
    std::vector <Entity*> targets;

    if (ai_times_attacked < 2) {
        targets.push_back (combatants [target_index]);
        this->skills [ATTACK]->use (this, targets);
        ai_times_attacked++;
    } else {
        targets.push_back (this);
        this->skills [BOOST_ATTACK]->use (this, targets);
        ai_times_attacked = 0;
    }
}
