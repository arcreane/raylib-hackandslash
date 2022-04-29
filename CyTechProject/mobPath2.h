#pragma once
#include "Mob.h"
class MobPath2 : public Mob
{
public:
	MobPath2(Rectangle rec);
	void setMob(Rectangle rec) override; 
	void setMob(Rectangle rec, bool o, float d, float a) override;
	void pathMob(Joueur player) override;
	Mob* copy() override;
};

