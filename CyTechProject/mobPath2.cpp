#include "mobPath2.h"

MobPath2::MobPath2(Rectangle rec) {
    pos_dim = rec;
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

    float distance = sqrt((playerX - mobX) * (playerX - mobX) + (playerY - mobY) * (playerY - mobY));
    this->setX(this->getX() + (playerX - mobX) / distance);
    this->setY(this->getY() + (playerY - mobY) / distance);
}