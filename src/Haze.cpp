#include "Haze.h"
#include "Entity.h"
#include <iostream>

Haze::Haze()
{
    turns_left = 1;
    name = "Haze";
}

Haze::~Haze()
{
    //dtor
}

void Haze::on_parent_turn (Entity* parent) {
    std::cout << parent->name << " took damage from the haze!" << std::endl;
    parent->health -= 2;
}
