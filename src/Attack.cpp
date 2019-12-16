#include "Attack.h"

Attack::Attack()
{
    name = "Attack";
    description = "A basic attack. Deals damage equal to the user's attack.";
    energy_cost = 2;
}

Attack::~Attack()
{
    //dtor
}

void Attack::use (Entity* user, std::vector <Entity*> targets) {
    Skill::use (user, targets);
    int damage = user->attack;

    if (user->faction == "player") {
        std::vector <Entity*> player_targets = find_targets (targets, 1);
        user->damage (player_targets [0], damage);
    } else {
        if (targets.size () == 1) {
            user->damage (targets [0], damage);
        }
    }
}
