#include "Mob.h"


void Mob::setRectangle(Rectangle rec) {
    this->pos_dim = rec;
}

void Mob::setMob(Rectangle rec, bool o, float d, float a)
{
    this->pos_dim = rec;
}

void Mob::setMob(Rectangle rec)
{   
    this->pos_dim = rec;
}

Mob::Mob(Rectangle rec) {
    pos_dim = rec;
}

Mob::Mob() {
    pos_dim = {0,0,0,0};
}