#include "Personnage.h"
#include "Joueur.h"

#pragma once
class Mob : public Personnage {
public:
	void setRectangle(Rectangle rec);
	virtual void setMob(Rectangle rec, bool o, float d, float a);
	virtual void setMob(Rectangle rec);
	virtual void pathMob(Joueur player) {};
	virtual void animation_run_droite(Vector2 position, int currentFrame){};
	virtual void animation_run_gauche(Vector2 position, int currentFrame) {};
	virtual void Init_animation_zombie() {};
	Mob(Rectangle rec);
	Mob();
};

