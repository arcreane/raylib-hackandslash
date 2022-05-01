#pragma once
#include "Mob.h"
class Portail : public Mob
{
public:
	Portail(Rectangle rec);
	void setMob(Rectangle rec) override;
	Mob* copy() override;
};

