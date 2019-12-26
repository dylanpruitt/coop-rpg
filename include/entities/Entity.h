#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include <string>
#include <random>
#include "statuses/Status.h"

class Skill;

class Entity
{
    public:
        Entity();
        virtual ~Entity();

        std::string name;
        std::string faction = "enemy";

        int health = 14;
        int max_health = 14;

        int energy = 5;
        int max_energy = 10;

        int attack = 1;
        int defense = 1;

        int level = 1;
        int experience = 0;

        std::vector <Skill*> skills;

        std::vector <Status*> statuses;

        bool is_alive ();

        bool has_status (std::string status_name);

        void remove_status (std::string status_name);

        void damage (Entity* target, int amount);

        virtual void AI (std::vector <Entity*> combatants);

        void promote ();
    protected:
        int target_lowest_health_enemy (std::vector <Entity*> combatants);

        int target_highest_health_enemy (std::vector <Entity*> combatants);

        int target_random_enemy (std::vector <Entity*> combatants);
};

#endif // ENTITY_H
