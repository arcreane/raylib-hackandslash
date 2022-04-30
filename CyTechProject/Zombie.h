#include "Mob.h"
#include "Map.h"

#pragma once
class Zombie : public Mob
{
protected:
	Platform* _p;
public:
	Zombie(Rectangle rec, bool o, Map* m);
	float getDistance(Platform* p);
	Platform* getClosestPlatform(Map* m);
	void pathMob(Joueur player) override;
};

