#include "ArmeDistance.h"

void ArmeDistance::setArme(float radius)
{
	this->hitBox = { 0, 0, radius };
	this->cooldown = 100;
	this->etat = false;
	this->time = 0;
}
