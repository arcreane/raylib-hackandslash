#include "../includes/Scythe.h"

void Scythe::setArme(float radius)
{
	this->hitBox = { 0, 0, radius };
	this->cooldown = 500;
	this->etat = false;
	this->time = 0;
	this->active = false;
	this->possede = true;
	this->item.Init_animation_scythe();
}

void Scythe::setOn(Vector2 pos) {
	this->hitBox.x = pos.x;
	this->hitBox.y = pos.y;
	this->positionDepart.x = pos.x;
	this->positionDepart.y = pos.y - 200;
	this->etat = true;
	this->active = true;
}

void Scythe::setOut() {
	this->active = false;
}

void Scythe::setOff() {
	this->etat = false;
	this->active = false;
	this->time = 0;
}

void Scythe::updatePositon() {
	if (this->direction) this->hitBox.x = this->positionDepart.x + time * 5;
	else this->hitBox.x = this->positionDepart.x - time * 5;
	this->hitBox.y = this->positionDepart.y + (0.05 * (time * 5 - 300)) * (0.05 * (time * 5 - 300));
}

void Scythe::updateArme(Joueur player) {
	if (IsKeyDown(KEY_Y) && !this->etat) {
		this->setOn(player.getPosition());
		this->setDirection(player.getOrientation());
	}
	if (this->getEtat()) {
		this->item.drawItem({ 20,20 }, BLACK);
		this->setCd();
		if (this->getActive()) {
			// DrawCircle(this->getX(), this->getY(), this->getRadius(), PINK);
			this->updatePositon();
		}
		if (this->getX() < -20 || this->getX() > 1620 || this->getY() > 920) {
			this->setOut();
		}
		if (this->getCd() <= 0) {
			this->setOff();
		}
	}
	else this->item.drawItem({ 20,20 }, WHITE);
}

void Scythe::setPossetion(bool p)
{
	this->possede = p;
	this->setOut();
}

void Scythe::resetTime() {
	this->time = 0;
}


Vector2 Scythe::getPosition() {
	return { this->hitBox.x, this->hitBox.y };
}

float Scythe::getX()
{
	return this->hitBox.x;
}

float Scythe::getY()
{
	return this->hitBox.y;
}

float Scythe::getRadius()
{
	return this->hitBox.radius;
}

bool Scythe::getActive() {
	return this->active;
}

bool Scythe::possetion() {
	return this->possede;
}