#ifndef HAZE_H
#define HAZE_H

#include <Status.h>


class Haze : public Status
{
    public:
        Haze();
        virtual ~Haze();

        void on_parent_turn (Entity* parent);
    protected:

    private:
};

#endif // HAZE_H
