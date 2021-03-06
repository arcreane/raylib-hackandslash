#include "Joueur.h"
#include <string>

#pragma once
class Mob : public Personnage {
protected:
	std::string type;
	bool isKillable = true;
public:
	void setRectangle(Rectangle rec);
	virtual void setMob(Rectangle rec, bool o, float d, float a);
	virtual void setMob(Rectangle rec);
	virtual void pathMob(Joueur player) {};
	virtual Mob* copy();
	virtual void animation_run_droite(Vector2 position, int currentFrame){};
	virtual void animation_run_gauche(Vector2 position, int currentFrame) {};
	virtual void Init_animation_zombie() {};
	bool getIsKillable();
	std::string getType();
	Mob(Rectangle rec);
	Mob();
};

