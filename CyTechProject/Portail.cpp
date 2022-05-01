#include "Portail.h"

Portail::Portail(Rectangle rec, std::string type)
{
	hitBox = rec;
	this->type = type;
}

void Portail::setItem(Rectangle rec) {
	this->hitBox = rec;
}

Item* Portail::copy() {
	return new Portail(this->hitBox, this->type);
}