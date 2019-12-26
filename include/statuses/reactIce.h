#ifndef REACTICE_H
#define REACTICE_H

#include <Status.h>


class reactIce : public Status
{
    public:
        reactIce();
        virtual ~reactIce();

        void on_ice_damage (Entity* parent, std::vector <Entity*> combatants);
    protected:

    private:
};

#endif // REACTICE_H
