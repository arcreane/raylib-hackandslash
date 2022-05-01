#include "DeathTouch.h"

void DeathTouch::setArme()
{
	this->hitBox = { 0, 0, 16, 48 };
	this->cooldown = 300;
	this->etat = false;
	this->time = 0;
	this->active = false;
}

void DeathTouch::setOn(Vector2 pos)
{
	this->hitBox.x = pos.x;
	this->hitBox.y = pos.y;
	this->etat = true;
	this->active = true;
}

void DeathTouch::setOut()
{
	this->active = false;
}

void DeathTouch::setOff()
{
	this->etat = false;
	this->active = false;
	this->time = 0;
}

void DeathTouch::updatePositon()
{
	if (this->direction) this->hitBox.x += 5;
	else this->hitBox.x -= 5;
}

void DeathTouch::updateArme(Joueur player)
{
	if (IsKeyDown(KEY_H) && !this->etat) {
		this->setOn(player.getPosition());
		this->setDirection(player.getOrientation());
	}
	if (this->getEtat()) {
		DrawRectangleRec({ 60,20,20,20 }, RED);
		this->setCd();
		if (this->getActive()) {
			//DrawRectangleRec(this->getRectangle(), PINK);
			this->updatePositon();
		}
		if (this->getX() < -20 || this->getX() > 1620 || this->getY() > 920) {
			this->setOut();
		}
		if (this->getCd() <= 0) {
			this->setOff();
		}
	}
	else DrawRectangleRec({ 60,20,20,20 }, GREEN);
}

Rectangle DeathTouch::getRectangle() {
	return this->hitBox;
}

Vector2 DeathTouch::getPosition()
{
	return {this->hitBox.x, this->hitBox.y};
}

float DeathTouch::getX()
{
	return this->hitBox.x;
}

float DeathTouch::getY()
{
	return this->hitBox.y;
}