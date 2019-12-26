#ifndef LIGHTNINGBUG_H
#define LIGHTNINGBUG_H

#include "Entity.h"

class lightningBug : public Entity
{
    public:
        lightningBug();
        virtual ~lightningBug();

        void AI (std::vector <Entity*> combatants);
    protected:

    private:
};

#endif // LIGHTNINGBUG_H
