#include "skills/Ice.h"

Ice::Ice()
{
    name = "Ice";
    description = "Attacks all enemies for low damage.";
    energy_cost = 5;
}

Ice::~Ice()
{
    //dtor
}

void Ice::use (Entity *user, std::vector <Entity*> targets) {
    Skill::use (user, targets);
    int damage = user->attack;
    if (user->faction == "player") {
        for (Entity* combatant : targets) {
            if (!(combatant->faction == "player") && combatant->is_alive ()) {
                user->damage (combatant, damage);
                for (int i = 0; i < combatant->statuses.size (); i++) {
                    std::vector <Entity*> player; player.push_back (user);
                    combatant->statuses [i]->on_ice_damage (combatant, player);
                }
            }
        }
    } else {
        for (Entity* target : targets) {
            user->damage (target, damage);
        }
    }
}
