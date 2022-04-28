#include "Personnage.h"
#include "Joueur.h"
#include <string>

#pragma once
class Mob : public Personnage {
protected:
	std::string type;
public:
	void setRectangle(Rectangle rec);
	virtual void setMob(Rectangle rec, bool o, float d, float a);
	virtual void setMob(Rectangle rec);
	virtual void pathMob(Joueur player) {};
	virtual void animation_run_droite(Vector2 position, int currentFrame){};
	virtual void animation_run_gauche(Vector2 position, int currentFrame) {};
	virtual void Init_animation_zombie() {};
	std::string getType();
	Mob(Rectangle rec);
	Mob();
};

