#include "Fire.h"

Fire::Fire()
{
    name = "Fire";
    description = "Attacks one enemy for medium damage.";
    energy_cost = 5;
}

Fire::~Fire()
{
    //dtor
}

void Fire::use (Entity *user, std::vector <Entity*> targets) {
    Skill::use (user, targets);
    int damage = 3 + user->attack;
    if (user->faction == "player") {
        std::vector <Entity*> player_targets = find_targets (targets, 1);
        user->damage (player_targets [0], damage);
    } else {
        if (targets.size () == 1) {
            user->damage (targets [0], damage);
        }
    }
}
