#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"
#include "Entity.h"
#include <vector>

class Dungeon
{
    public:
        Dungeon ();
        virtual ~Dungeon ();

        void loop (std::vector <Entity*> players);
    protected:
        std::string name;
        std::vector <Room> rooms;
    private:
        int room_number = 0;

        bool faction_members_remain (std::string faction, std::vector <Entity*> combatants);
};

#endif // DUNGEON_H
