#include "Pass.h"

Pass::Pass()
{
    name = "Pass";
    description = "Do nothing.";
    energy_cost = 0;
}

Pass::~Pass()
{
    //dtor
}

void Pass::use (Entity* user, std::vector <Entity*> targets) {
    Skill::use (user, targets);
}
