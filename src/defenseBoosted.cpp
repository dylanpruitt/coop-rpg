#include "defenseBoosted.h"
#include "Entity.h"

defenseBoosted::defenseBoosted (int defense_boost)
{
    turns_left = 99;
    this->defense_boost = defense_boost;
    this->name = "Defense Boosted";
}

defenseBoosted::~defenseBoosted ()
{
    //dtor
}

void defenseBoosted::on_battle_end (Entity* parent) {
    parent->defense -= defense_boost;
}
