#include "raylib.h"
#include "raymath.h"
#include "Dimension.h"

#pragma once
class Platform
{
private:
	Rectangle pos_dim;
public:
	void setPlatform(Rectangle pd);
	Platform(Rectangle rec);
	Platform();
	Rectangle getRectangle();
	Vector2 getPosition();
	float getY();
	float getXd();
	Dimension getDimension();
	float getWidth();
	float getHeight();
	float getXDroite();
	float getYBas();
};

