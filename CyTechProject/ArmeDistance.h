#include "Arme.h"

#pragma once
class ArmeDistance : public Arme
{
private:
	Circle hitBox;
	Vector2 positionDepart;
	bool active;
public:
	void setArme(float radius);
	void setOn(Vector2 pos);
	void setOut();
	void updatePositon();

	float getX();
	float getY();
	float getRadius();
	bool getActive();
};

