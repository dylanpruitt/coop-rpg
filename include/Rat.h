#ifndef RAT_H
#define RAT_H

#include <Entity.h>


class Rat : public Entity
{
    public:
        Rat();
        virtual ~Rat();

        void AI (std::vector <Entity*> combatants);
    protected:

    private:
};

#endif // RAT_H
