#include "attackBoosted.h"
#include "Entity.h"

attackBoosted::attackBoosted (int attack_boost)
{
    turns_left = 99;
    this->attack_boost = attack_boost;
    this->name = "Attack Boosted";
}

attackBoosted::~attackBoosted ()
{
    //dtor
}

void attackBoosted::on_battle_end (Entity* parent) {
    parent->attack -= attack_boost;
}
