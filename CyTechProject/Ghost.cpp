#include "Ghost.h"

Ghost::Ghost(Rectangle rec) {
    pos_dim = rec;
    this->type = "ghost";
}

void Ghost::setMob(Rectangle rec, bool o, float d, float a) {
    this->pos_dim = rec;
}

void Ghost::setMob(Rectangle rec) {
    this->pos_dim = rec;
}

void Ghost::pathMob(Joueur player) {
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

}

Mob* Ghost::copy() {
    return new Ghost(this->pos_dim);
}