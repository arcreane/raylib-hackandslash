#include "DeathTouch.h"

void DeathTouch::setArme()
{
	this->hitBox = { 0, 0, 16, 48 };
	this->cooldown = 100;
	this->etat = false;
	this->time = 0;
	this->active = false;
}

void DeathTouch::setOn(Vector2 pos)
{

}

void DeathTouch::setOut()
{
}

void DeathTouch::setOff()
{
}

void DeathTouch::updatePositon()
{
}

void DeathTouch::updateArme(Joueur player)
{
	//if (IsKeyPr)
}
