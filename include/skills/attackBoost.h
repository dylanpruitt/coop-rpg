#ifndef ATTACKBOOST_H
#define ATTACKBOOST_H

#include <skills/Skill.h>

class attackBoost : public Skill
{
    public:
        attackBoost();
        virtual ~attackBoost();

        void use (Entity *user, std::vector <Entity*> targets);
};

#endif // ATTACKBOOST_H
