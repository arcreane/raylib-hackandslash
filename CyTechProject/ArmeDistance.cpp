#include "ArmeDistance.h"

void ArmeDistance::setArme(float radius)
{
	this->hitBox = { 0, 0, radius };
	this->cooldown = 500;
	this->etat = false;
	this->time = 0;
	this->active = true;
}

void ArmeDistance::setOn(Vector2 pos) {
	this->hitBox.x = pos.x;
	this->hitBox.y = pos.y;
	this->positionDepart.x = pos.x;
	this->positionDepart.y = pos.y - 200;
	this->etat = true;
	this->active = true;
}

void ArmeDistance::setOut() {
	this->active = false;
}

void ArmeDistance::updatePositon() {
	if (this->direction) this->hitBox.x = this->positionDepart.x + time * 5;
	else this->hitBox.x = this->positionDepart.x - time * 5;
	this->hitBox.y = this->positionDepart.y + (0.05 * (time * 5 - 300)) * (0.05 * (time * 5 - 300));
}


Vector2 ArmeDistance::getPosition() {
	return { this->hitBox.x, this->hitBox.y };
}

float ArmeDistance::getX()
{
	return this->hitBox.x;
}

float ArmeDistance::getY()
{
	return this->hitBox.y;
}

float ArmeDistance::getRadius()
{
	return this->hitBox.radius;
}

bool ArmeDistance::getActive() {
	return this->active;
}
