#ifndef ATTACK_H
#define ATTACK_H
#include "Skill.h"

class Attack : public Skill
{
    public:
        Attack();
        virtual ~Attack();

        void use (Entity* user, std::vector <Entity*> combatants);
};

#endif // ATTACK_H
