#include "raylib.h"
#include "raymath.h"
#include "Struct.h"

#pragma once
class Arme {
protected:
	bool etat;
	bool direction;
	int cooldown;
	int active;
	int time;

public:
	void setOff();
	void setDirection(bool d);
	void setCd();
	
	bool getEtat();
	bool getDirection();
	int getCd();
	int getActive();

};

