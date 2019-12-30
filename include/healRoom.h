#ifndef HEALROOM_H
#define HEALROOM_H
#include "Room.h"

class healRoom : public Room
{
    public:
        healRoom();
        virtual ~healRoom();
        virtual void event (std::vector <Entity*> players);
};

#endif // HEALROOM_H
