#ifndef DEFENSEBOOSTED_H
#define DEFENSEBOOSTED_H
#include "Status.h"

class defenseBoosted : public Status
{
    public:
        defenseBoosted (int defense_boost);
        virtual ~defenseBoosted();

        void on_battle_end (Entity* parent);
    protected:

    private:
        int defense_boost = 0;
};

#endif // DEFENSEBOOSTED_H
