#include "raylib.h"
#include "raymath.h"
#include "Joueur.h"
#include "Struct.h"
#include <string>

#pragma once
class Arme {
protected:
	std::string type;
	bool etat;
	bool direction;
	int cooldown;
	int active;
	int time;

public:
	void setDirection(bool d);
	void setCd();
	
	bool getEtat();
	bool getDirection();
	int getCd();
	int getActive();

};

