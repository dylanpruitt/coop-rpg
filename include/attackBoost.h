#ifndef ATTACKBOOST_H
#define ATTACKBOOST_H

#include <Skill.h>


class attackBoost : public Skill
{
    public:
        attackBoost();
        virtual ~attackBoost();

        void use (Entity* user, std::vector <Entity*> targets);
    protected:

    private:
};

#endif // ATTACKBOOST_H
