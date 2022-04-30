#include "Portail.h"

Portail::Portail(Rectangle rec)
{
	pos_dim = rec;
	this->type = "Portail";
	this->isKillable = false;
}

void Portail::setMob(Rectangle rec) {
	this->pos_dim = rec;
}

Mob* Portail::copy() {
	return new Portail(this->pos_dim);
}