#ifndef DEFENSEBOOST_H
#define DEFENSEBOOST_H

#include <skills/Skill.h>

class defenseBoost : public Skill
{
    public:
        defenseBoost();
        virtual ~defenseBoost();

        void use (Entity *user, std::vector <Entity*> targets);
};

#endif // DEFENSEBOOST_H
