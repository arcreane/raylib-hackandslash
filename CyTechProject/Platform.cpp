#include "Platform.h"

void Platform::setPlatform(Rectangle pd) {
	this->pos_dim = pd;
}

Rectangle Platform::getRectangle() {
	return this->pos_dim;
}

Vector2 Platform::getPosition() {
	return { this->pos_dim.x, this->pos_dim.y };
}

float Platform::getY() {
	return this->pos_dim.y;
}

float Platform::getXd() {
	return this->pos_dim.x;
}

Dimension Platform::getDimension() {
	return { this->pos_dim.width, this->pos_dim.height };
}

float Platform::getWidth() {
	return this->pos_dim.width;
}

float Platform::getHeight() {
	return this->pos_dim.height;
}

float Platform::getXDroite() {
	return (this->pos_dim.x + this->pos_dim.width);
}

float Platform::getYBas() {
	return (this->pos_dim.y + this->pos_dim.height);
}

