#include "Arme.h"


void Arme::setDirection(bool d) {
	this->direction = d;
}

void Arme::setCd() {
	this->time++;
}


bool Arme::getEtat() {
	return this->etat;
}

bool Arme::getDirection() {
	return this->direction;
}

int Arme::getCd() {
	return (this->cooldown - this->time);
}

int Arme::getActive() {
	return (this->active - this->time);
}