#include <iostream>
#include "Game.h"
#include "Rat.h"

int main()
{
    Game game;
    Entity* test = new Rat ();

    std::vector <Entity*> targets; targets.push_back (test);

    game.battle (targets);
    return 0;
}
