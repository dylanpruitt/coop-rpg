#ifndef WARHAWK_H
#define WARHAWK_H

#include <Entity.h>


class Warhawk : public Entity
{
    public:
        Warhawk();
        virtual ~Warhawk();

        void AI (std::vector <Entity*> combatants);
    private:
        int turn_counter = 1;
};

#endif // WARHAWK_H
