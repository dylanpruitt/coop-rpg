#ifndef FIRE_H
#define FIRE_H

#include <Skill.h>


class Fire : public Skill
{
    public:
        Fire();
        virtual ~Fire();

        void use (Entity *user, std::vector <Entity*> targets);
};

#endif // FIRE_H
