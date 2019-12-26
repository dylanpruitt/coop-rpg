#ifndef ROOM_H
#define ROOM_H
#include "entities/Entity.h"
#include <vector>

class Room
{
    public:
        Room ();
        Room (std::vector <Entity*> encounter);
        virtual ~Room ();

        std::string name;

        std::vector <Entity*> encounter;

        void event (std::vector <Entity*> players);

    private:
        void battle (std::vector <Entity*> players);

        bool faction_members_remain (std::string faction, std::vector <Entity*> players);

        void display_combatant_information (std::vector <Entity*> players);

        void display_skills (Entity* player);
};

#endif // ROOM_H
