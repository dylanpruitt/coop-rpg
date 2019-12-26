#include "skills/attackBoost.h"
#include "attackBoosted.h"
#include <iostream>

attackBoost::attackBoost()
{
    name = "Attack Boost";
    description = "The target gains 2 strength, which lets you deal more damage.";
    energy_cost = 5;
}

attackBoost::~attackBoost()
{
    //dtor
}

void attackBoost::use (Entity* user, std::vector <Entity*> targets) {
    Skill::use (user, targets);
    if (user->faction == "player") {
        std::vector <Entity*> player_targets = find_targets (targets, 1);
        player_targets [0]->attack += 2;
        player_targets [0]->statuses.push_back (new attackBoosted (2));
    } else {
        if (targets.size () == 1) {
            targets [0]->attack += 2;
            targets [0]->statuses.push_back (new attackBoosted (2));
        }
    }
}
