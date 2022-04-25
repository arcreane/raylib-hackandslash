#include "Arme.h"


void Arme::setArme(Dimension hb, int cd, int t) {
	this->hitBox = { 0, 0, hb.width, hb.height };
	this->cooldown = cd;
	this->active = t;
	this->etat = false;
	this->time = 0;
}

void Arme::setOn(Vector2 pos) {
	this->hitBox.x = pos.x;
	this->hitBox.y = pos.y;
	this->etat = true;
}

void Arme::setOff() {
	this->etat = false;
	this->time = 0;
}

void Arme::setCd() {
	this->time++;
}


bool Arme::getEtat() {
	return this->etat;
}
Rectangle Arme::getRectangle() {
	return this->hitBox;
}

float Arme::getWidth() {
	return this->hitBox.width;
}

int Arme::getCd() {
	return (this->cooldown - this->time);
}

int Arme::getActive() {
	return (this->active - this->time);
}