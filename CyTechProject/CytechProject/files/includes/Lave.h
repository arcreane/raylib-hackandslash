#pragma once
#include "Mob.h"
class Lave : public Mob
{
public:
	Lave(Rectangle rec);
	void setMob(Rectangle rec) override;
	Mob* copy() override;
};

