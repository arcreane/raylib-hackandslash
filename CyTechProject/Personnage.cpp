#include "Personnage.h"

void Personnage::setPersonnage(Rectangle p) {
        this->pos_dim = p;
        this->orientation = true;
        this->speed = 0;
        this->canJump = false;
        this->isAlive = true;
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

void Personnage::setXDroite(float x) {
    this->pos_dim.x = x - this->pos_dim.width;
}

void Personnage::setYBas(float y) {
    this->pos_dim.y = y - this->pos_dim.height;
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

void Personnage::setIsAlive(bool ia) {
    this->isAlive = ia;
}


Rectangle Personnage::getRectangle() {
    return this->pos_dim;
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

bool Personnage::getIsAlive() {
    return this->isAlive;
}

Vector2 Personnage::getCenter() {
    return { this->pos_dim.x + this->pos_dim.width / 2, this->pos_dim.y + this->pos_dim.height / 2 };
}