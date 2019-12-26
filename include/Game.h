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

        void loop ();
    protected:

    private:
        void battle (std::vector <Entity*> enemies);

        bool faction_members_remain (std::string faction, std::vector <Entity*> combatants);

        void display_combatant_information (std::vector <Entity*> enemies);

        void display_skills (Entity* player);

        void create_player ();

};

#endif // GAME_H
