#include "Arme.h"
#include "Animation_Scythe.h"

#pragma once
class ArmeDistance : public Arme
{
private:
	Circle hitBox;
	Vector2 positionDepart;
	bool active;
	bool possede;
	Animation_Scythe item;
public:
	void setArme(float radius);
	void setOn(Vector2 pos);
	void setOut();
	void setOff();
	void updatePositon();
	void updateArme(Joueur player);
	void setPossetion(bool p);
	void resetTime();

	Vector2 getPosition();
	float getX();
	float getY();
	float getRadius();
	bool getActive();
	bool possetion();
};

