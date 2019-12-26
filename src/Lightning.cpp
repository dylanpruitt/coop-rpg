#include "Lightning.h"

Lightning::Lightning()
{
    name = "Lightning";
    description = "Attacks a random enemy for high damage.";
    energy_cost = 5;
}

Lightning::~Lightning()
{
    //dtor
}

void Lightning::use (Entity *user, std::vector <Entity*> targets) {
    Skill::use (user, targets);
    int damage = 6 + user->attack;
    if (user->faction == "player") {
        bool target_is_valid = false;
        int target_index = -1;

        while (!target_is_valid) {
            target_index = rand () % (targets.size () - 1) + 1;
            if (targets [target_index]->faction != "player" && targets [target_index]->health > 0) {
                target_is_valid = true;
            }
        }

        std::vector <Entity*> player_targets; player_targets.push_back (targets [target_index]);
        user->damage (player_targets [0], damage);
    } else {
        if (targets.size () == 1) {
            user->damage (targets [0], damage);
        }
    }
}
