#include "Personnage.h"
#include <vector>

#pragma once
class Mob : public Personnage {
private:
public:
	void setRectangle(Rectangle rec);
	virtual void setMob(Rectangle rec, bool o, float d, float a);
	virtual void setMob(Rectangle rec);
	virtual void pathMob() {};

	Mob(Rectangle rec);
	Mob();
};

