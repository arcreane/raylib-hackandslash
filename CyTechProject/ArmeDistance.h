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
	void setOff();
	void updatePositon();
	void updateArme(Joueur player);

	Vector2 getPosition();
	float getX();
	float getY();
	float getRadius();
	bool getActive();
};

