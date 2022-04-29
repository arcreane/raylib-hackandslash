#pragma once
#include "Mob.h"
class Ghost : public Mob
{
public:
	Ghost(Rectangle rec);
	void setMob(Rectangle rec) override; 
	void setMob(Rectangle rec, bool o, float d, float a) override;
	void pathMob(Joueur player) override;
	Mob* copy() override;
};

