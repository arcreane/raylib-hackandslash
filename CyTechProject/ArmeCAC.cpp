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

void ArmeCAC::updateArme(Joueur player)
{
	if (IsKeyDown(KEY_J) && !this->etat) {
		if (player.getOrientation() == true) {
			this->setOn({ player.getXDroite(), player.getY() });
			this->setDirection(true);
		}
		if (player.getOrientation() == false) {
			this->setOn({ player.getX() - this->getWidth(), player.getY() });
			this->setDirection(false);
		}
	}
	if (this->getEtat()) {
		if (this->getDirection()) {
			this->setOn({ player.getXDroite(), player.getY() });
		}
		else {
			this->setOn({ player.getX() - this->getWidth(), player.getY() });
		}
		this->setCd();
		if (this->getActive() > 0) {
			//DrawRectangleRec(this->getRectangle(), YELLOW);
		}
		if (this->getCd() <= 0) {
			this->setOff();
		}
	}
}

Rectangle ArmeCAC::getRectangle() {
	return this->hitBox;
}

float ArmeCAC::getWidth() {
	return this->hitBox.width;
}

int ArmeCAC::getActive() {
	return (this->active - this->time);
}