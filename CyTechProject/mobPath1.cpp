#include "mobPath1.h"

MobPath1::MobPath1(Rectangle rec, bool o, float d, float a) {
    pos_dim = rec;
    orientation = o;
    dep = d;
    arr = a;
    this->type = "ratKing";
}

void MobPath1::setMob(Rectangle rec, bool o, float d, float a) {
    this->pos_dim = rec;
    this->orientation = o;
    this->dep = d;
    this->arr = a;
}

void MobPath1::pathMob(Joueur player)
{
    if (this->orientation) {
        this->setX(this->getX() + 1);
        if (this->getX() > this->arr) {
            this->setOrientation(false);
        }
    }
    else {
        this->setX(this->getX() - 1);
        if (this->getX() < this->dep) {
            this->setOrientation(true);
        }
    }
}

Mob* MobPath1::copy() {
    return (new MobPath1(this->pos_dim,this->orientation,this->dep,this->arr));
}