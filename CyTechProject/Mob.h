#include "Personnage.h"
#include "Joueur.h"

#pragma once
class Mob : public Personnage {
public:
	void setRectangle(Rectangle rec);
	virtual void setMob(Rectangle rec, bool o, float d, float a);
	virtual void setMob(Rectangle rec);
	virtual void pathMob(Joueur player) {};
	Mob(Rectangle rec);
	Mob();
};

