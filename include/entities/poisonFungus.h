#ifndef POISONFUNGUS_H
#define POISONFUNGUS_H

#include <Entity.h>


class poisonFungus : public Entity
{
    public:
        poisonFungus();
        virtual ~poisonFungus();

        void AI (std::vector <Entity*> combatants);
    protected:

    private:
};

#endif // POISONFUNGUS_H
