#ifndef PASS_H
#define PASS_H
#include "Skill.h"

class Pass : public Skill
{
    public:
        Pass();
        virtual ~Pass();

        void use (Entity* user, std::vector <Entity*> targets);
    protected:

    private:
};

#endif // PASS_H
