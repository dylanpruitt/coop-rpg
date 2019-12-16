#ifndef DODGESKILL_H
#define DODGESKILL_H
#include "Skill.h"

class dodgeSkill : public Skill
{
    public:
        dodgeSkill();
        virtual ~dodgeSkill();

        void use (Entity* user, std::vector <Entity*> combatants);
};

#endif // DODGESKILL_H
