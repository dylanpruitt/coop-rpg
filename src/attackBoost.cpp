#include "attackBoost.h"

attackBoost::attackBoost()
{
    name = "Attack Boost";
    description = "Boosts the amount of damage that you deal.";
    energy_cost = 6;
}

attackBoost::~attackBoost()
{
    //dtor
}

void attackBoost::use (Entity* user, std::vector <Entity*> targets) {
    user->attack += 2;
}
