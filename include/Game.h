#ifndef GAME_H
#define GAME_H
#include <vector>
#include "entities/Entity.h"
#include "Room.h"


class Game
{
    public:
        Game();
        virtual ~Game();

        std::vector <Entity*> players;

        void loop ();
    protected:

    private:
        Room room;

        bool faction_members_remain (std::string faction, std::vector <Entity*> combatants);

        void create_player ();

};

#endif // GAME_H
