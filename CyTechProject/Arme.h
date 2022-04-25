#include "raylib.h"
#include "raymath.h"
#include "Dimension.h"

#pragma once
class Arme {
private:
	bool etat;
	Rectangle hitBox;
	bool direction;
	int cooldown;
	int active;
	int time;

public:
	void setArme(Dimension hb, int cd, int t);
	void setOn(Vector2 pos);
	void setOff();
	void setDirection(bool d);
	void setCd();
	
	bool getEtat();
	Rectangle getRectangle();
	float getWidth();
	bool getDirection();
	int getCd();
	int getActive();

};

