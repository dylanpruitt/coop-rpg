#include "lightningBug.h"
#include "skills/Lightning.h"
#include "skills/Fire.h"

lightningBug::lightningBug()
{
    name = "Lightning Bug";
    health = 17;
    max_health = 17;

    attack = 2;
    defense = 0;

    experience = 4;

    skills.push_back (new Lightning ());
    skills.push_back (new Fire ());
}

lightningBug::~lightningBug()
{
    //dtor
}

void lightningBug::AI (std::vector <Entity*> combatants) {
    const int LIGHTNING = 0, FIRE = 1;

    int target_index = target_random_enemy (combatants);
    std::vector <Entity*> targets;
    targets.push_back (combatants [target_index]);

    int random_number = rand () % 3;

    if (random_number < 2) {
        this->skills [LIGHTNING]->use (this, targets);
    } else {
        this->skills [FIRE]->use (this, targets);
    }
}
