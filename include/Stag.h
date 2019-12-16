#ifndef STAG_H
#define STAG_H
#include "Entity.h"

class Stag : public Entity
{
    public:
        Stag();
        virtual ~Stag();

        void AI (std::vector <Entity*> combatants);
    protected:

    private:
};

#endif // STAG_H
