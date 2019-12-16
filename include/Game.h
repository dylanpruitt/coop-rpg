#ifndef GAME_H
#define GAME_H
#include <vector>
#include "Entity.h"

class Game
{
    public:
        Game();
        virtual ~Game();

        std::vector <Entity*> players;

        void battle (std::vector <Entity*> enemies);
    protected:

    private:
        bool faction_members_remain (std::string faction, std::vector <Entity*> combatants);

        void display_player_information (Entity* player);

        void create_player ();

};

#endif // GAME_H
