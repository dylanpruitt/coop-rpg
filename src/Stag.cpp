#include "Stag.h"
#include "Attack.h"
#include "dodgeSkill.h"
#include <random>

Stag::Stag()
{
    name = "Stag";
    max_health = 26;
    health = 26;

    attack = 2;
    defense = 2;

    skills.push_back (new Attack ());
    skills.push_back (new dodgeSkill ());
}

Stag::~Stag()
{
    //dtor
}

void Stag::AI (std::vector <Entity*> combatants) {
    const int ATTACK = 0, DODGE = 1;

    int target_index = target_random_enemy (combatants);
    std::vector <Entity*> targets; targets.push_back (combatants [target_index]);

    if (health > (max_health / 2)) {
        this->skills [ATTACK]->use (this, targets);
    } else {
        int random_number = rand () % 5 + 1;

        if (random_number <= 3) {
            this->skills [ATTACK]->use (this, targets);
        } else {
            this->skills [DODGE]->use (this, targets);
        }
    }
}
