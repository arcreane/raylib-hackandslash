#include "Portail.h"

Portail::Portail(Rectangle rec)
{
	hitBox = rec;
	this->type = "portail";
}

void Portail::setItem(Rectangle rec) {
	this->hitBox = rec;
}

Item* Portail::copy() {
	return new Portail(this->hitBox);
}