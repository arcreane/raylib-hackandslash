#include "ArmeCAC.h"


void ArmeCAC::setArme(Dimension hb, int cd, int t) {
	this->hitBox = { 0, 0, hb.width, hb.height };
	this->cooldown = cd;
	this->active = t;
	this->etat = false;
	this->time = 0;
}

void ArmeCAC::setOn(Vector2 pos) {
	this->hitBox.x = pos.x;
	this->hitBox.y = pos.y;
	this->etat = true;
}

void ArmeCAC::setOff() {
	this->etat = false;
	this->time = 0;
}


Rectangle ArmeCAC::getRectangle() {
	return this->hitBox;
}

float ArmeCAC::getWidth() {
	return this->hitBox.width;
}