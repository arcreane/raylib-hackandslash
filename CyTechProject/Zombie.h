#include "Mob.h"
#include "Map.h"

#pragma once
class Zombie : public Mob
{
protected:
	Platform _p;
	Map* _m;
public:
	void setMob(Rectangle rec) override;
	Zombie(Rectangle rec, bool o, Map* m);
	Zombie(Rectangle rec, bool o, Platform p, Map* m);
	float getDistance(Platform p);
	void getClosestPlatform(Map* m);
	void pathMob(Joueur player) override;
	Mob* copy() override;
};

