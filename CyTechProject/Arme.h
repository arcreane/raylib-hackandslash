#include "raylib.h"
#include "raymath.h"
#include "Joueur.h"
#include "Map.h"
#include "Struct.h"
#include <string>

#pragma once
class Arme {
protected:
	std::string type;
	bool etat;
	bool direction;
	int cooldown;
	int time;

public:
	void setDirection(bool d);
	void setCd();
	
	bool getEtat();
	bool getDirection();
	int getCd();

};

