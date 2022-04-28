#include "Arme.h"

#pragma once
class ArmeDistance : public Arme
{
private:
	Circle hitBox;
public:
	void setArme(float radius);
};

