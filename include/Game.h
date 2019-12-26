#ifndef GAME_H
#define GAME_H
#include <vector>
#include "entities/Entity.h"
#include "Dungeon.h"


class Game
{
    public:
        Game();
        virtual ~Game();

        std::vector <Entity*> players;

        void loop ();
    protected:

    private:
        Dungeon dungeon;

        void create_player ();

};

#endif // GAME_H
