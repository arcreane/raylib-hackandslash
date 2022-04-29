#include "mobPath2.h"

MobPath2::MobPath2(Rectangle rec) {
    pos_dim = rec;
    this->type = "ghost";
}

void MobPath2::setMob(Rectangle rec, bool o, float d, float a) {
    this->pos_dim = rec;
}

void MobPath2::setMob(Rectangle rec) {
    this->pos_dim = rec;
}

void MobPath2::pathMob(Joueur player) {
    float mobX = this->getX(); 
    float mobY = this->getY(); 
    float playerX = player.getX(); 
    float playerY = player.getY();

    if (mobX < playerX)
        this->orientation = true;
    else this->orientation = false;

    float distance = sqrt((playerX - mobX) * (playerX - mobX) + (playerY - mobY) * (playerY - mobY));
    this->setX(this->getX() + 2.5*(playerX - mobX) / distance);
    this->setY(this->getY() + 2.5*(playerY - mobY) / distance);
    if (this->getX() < 0) {
        this->setOrientation(true);
    } else {
        this->setOrientation(false);
    }
}

Mob* MobPath2::copy() {
    return new MobPath2(this->pos_dim);
}