#include "Arme.h"

#pragma once
class ArmeCAC : public Arme
{
private:
	Rectangle hitBox;
public:
	void setArme(Dimension hb, int cd, int t);
	void setOn(Vector2 pos);
	void setOff();

	Rectangle getRectangle();
	float getWidth();

};

