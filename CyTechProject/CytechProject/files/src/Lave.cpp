#include "../includes/Lave.h"
Lave::Lave(Rectangle rec) {
    pos_dim = rec;
    this->type = "Lave";
    this->isKillable = false;
}
void Lave::setMob(Rectangle rec) {
    this->pos_dim = rec;
}

Mob* Lave::copy() {
    return new Lave(this->pos_dim);
}