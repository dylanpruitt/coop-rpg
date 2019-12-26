#ifndef AETHER_H
#define AETHER_H

#include <Entity.h>


class Aether : public Entity
{
    public:
        Aether();
        virtual ~Aether();

        void AI (std::vector <Entity*> combatants);
    protected:

    private:
        int turn_counter = 1;
};

#endif // AETHER_H
