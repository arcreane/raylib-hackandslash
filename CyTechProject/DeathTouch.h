#include "Arme.h"

#pragma once
class DeathTouch : public Arme
{
private:
	Rectangle hitBox;
public:
	void setArme();
	void setOn(Vector2 pos);
	void setOut();
	void setOff();
	void updatePositon();
	void updateArme(Joueur player);


};

