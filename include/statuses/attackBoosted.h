#ifndef ATTACKBOOSTED_H
#define ATTACKBOOSTED_H
#include "Status.h"

class attackBoosted : public Status
{
    public:
        attackBoosted (int attack_boost);
        virtual ~attackBoosted();

        void on_battle_end (Entity* parent);
    protected:

    private:
        int attack_boost = 0;
};

#endif // ATTACKBOOSTED_H
