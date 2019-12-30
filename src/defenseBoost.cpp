#include "skills/defenseBoost.h"
#include "defenseBoosted.h"
#include <iostream>

defenseBoost::defenseBoost()
{
    name = "Defense Boost";
    description = "The target gains 2 defense, which lets you take less damage.";
    energy_cost = 9;
}

defenseBoost::~defenseBoost()
{
    //dtor
}

void defenseBoost::use (Entity* user, std::vector <Entity*> targets) {
    Skill::use (user, targets);
    if (user->faction == "player") {
        std::vector <Entity*> player_targets = find_targets (targets, 1);
        player_targets [0]->defense += 2;
        player_targets [0]->statuses.push_back (new defenseBoosted (2));
    } else {
        if (targets.size () == 1) {
            targets [0]->defense += 2;
            targets [0]->statuses.push_back (new defenseBoosted (2));
        }
    }
}
