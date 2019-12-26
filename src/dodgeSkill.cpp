#include "skills/dodgeSkill.h"
#include "Dodge.h"

dodgeSkill::dodgeSkill()
{
    name = "Dodge";
    description = "Dodge an attack this turn.";
    energy_cost = 6;
}

dodgeSkill::~dodgeSkill()
{
    //dtor
}

void dodgeSkill::use (Entity *user, std::vector <Entity*> targets) {
    Skill::use (user, targets);
    user->statuses.push_back (new Dodge ());
}
