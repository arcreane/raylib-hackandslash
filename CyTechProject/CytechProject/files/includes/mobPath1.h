#include "Mob.h"

#pragma once
class MobPath1 : public Mob
{
private:
	float dep;
	float arr;
public:
	MobPath1(Rectangle rec, bool o, float d, float a);
	void setMob(Rectangle rec, bool o, float d, float a) override; 
	void pathMob(Joueur player) override;
};

