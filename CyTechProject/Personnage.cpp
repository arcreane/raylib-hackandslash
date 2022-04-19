#include "Personnage.h"

void Personnage::setPersonnage(Rectangle p, bool o, float s, bool cj) {
        this->pos_dim = p;
        this->orientation = o;
        this->speed = s;
        this->canJump = cj;
    }
void Personnage::setPosition(Vector2 p) {
    this->pos_dim.x = p.x;
    this->pos_dim.y = p.y;
}
void Personnage::setX(float x) {
    this->pos_dim.x = x;
}
void Personnage::setY(float y) {
    this->pos_dim.y = y;
}
void Personnage::setYBas(float y) {
    this->pos_dim.y = y + this->pos_dim.height;
}
void Personnage::setOrientation(bool b) {
    this->orientation = b;
}
void Personnage::setSpeed(float s) {
    this->speed = s;
}
void Personnage::setCanJump(bool cj) {
    this->canJump = cj;
}

Vector2 Personnage::getPosition() {
    return { this->pos_dim.x, this->pos_dim.y };
}
float Personnage::getX() {
    return this->pos_dim.x;
}
float Personnage::getY() {
    return this->pos_dim.y;
}
bool Personnage::getOrientation() {
    return this->orientation;
}
float Personnage::getSpeed() {
    return this->speed;
}
bool Personnage::getCanJump() {
    return this->canJump;
}
Dimension Personnage::getDimension() {
    return { this->pos_dim.width, this->pos_dim.height };
}

float Personnage::getWidth() {
    return this->pos_dim.width;
}

float Personnage::getHeight() {
    return this->pos_dim.height;
}

float Personnage::getXDroite() {
    return (this->pos_dim.x + this->pos_dim.width);
}

float Personnage::getYBas() {
    return (this->pos_dim.y + this->pos_dim.height);
}