#include "RatKing.h"

RatKing::RatKing(Rectangle rec, bool o, float d, float a) {
    pos_dim = rec;
    orientation = o;
    dep = d;
    arr = a;
    this->type = "ratKing";
}

void RatKing::setMob(Rectangle rec, bool o, float d, float a) {
    this->pos_dim = rec;
    this->orientation = o;
    this->dep = d;
    this->arr = a;
}

void RatKing::pathMob(Joueur player)
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

Mob* RatKing::copy() {
    return (new RatKing(this->pos_dim,this->orientation,this->dep,this->arr));
}