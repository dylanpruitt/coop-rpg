#ifndef SKILL_H
#define SKILL_H
#include <string>
#include <vector>
#include "Entity.h"
#include "textGraphics.h"

class Skill
{
    public:
        Skill();
        virtual ~Skill();

        std::string name;
        std::string description;

        int energy_cost;

        virtual void use (Entity* user, std::vector <Entity*> targets);

        std::vector <Entity*> find_targets (std::vector <Entity*> combatants, int number_of_targets);

    protected:
        int get_player_target (std::vector <Entity*> combatants);
    private:
};

#endif // SKILL_H
