#include "Rat.h"
#include "Attack.h"

Rat::Rat()
{
    name = "Rat";
    health = 7;
    max_health = 7;

    attack = 1;
    defense = 1;

    skills.push_back (new Attack ());
}

Rat::~Rat()
{
    //dtor
}

void Rat::AI (std::vector <Entity*> combatants) {
    const int ATTACK = 0;

    int target_index = target_random_enemy (combatants);
    std::vector <Entity*> targets; targets.push_back (combatants [target_index]);

    this->skills [ATTACK]->use (this, targets);
}
