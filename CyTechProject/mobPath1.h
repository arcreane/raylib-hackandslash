#include "Mob.h"

#pragma once
class MobPath1 : public Mob
{
private:
	float dep;
	float arr;
public:
	MobPath1(Rectangle rec, bool o, float d, float a);
	void setMob(Rectangle rec, bool o, float d, float a) override; // 0 : sans type, 1 : droite/gauche, 2 : focus perso
	//bool getOrientation(); // true => , false <=
	void pathMob(Joueur player) override;
	Mob* copy() override;
};

