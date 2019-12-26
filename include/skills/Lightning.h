#ifndef LIGHTNING_H
#define LIGHTNING_H

#include <skills/Skill.h>


class Lightning : public Skill
{
    public:
        Lightning();
        virtual ~Lightning();

        void use (Entity *user, std::vector <Entity*> targets);
};

#endif // LIGHTNING_H
