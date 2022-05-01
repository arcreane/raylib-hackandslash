#include "Arme.h"

#pragma once
class DeathTouch : public Arme
{
private:
	Rectangle hitBox;
	Map* _m;
	bool possede;
public:
	void setArme();
	void setOn(Vector2 pos, Map* m);
	void setOut();
	void setOff();
	void updatePositon();
	void updateArme(Joueur player, Map* m);

	Rectangle getRectangle();
	Vector2 getPosition();
	bool getActive();
	float getX();
	float getY();
	bool possetion();
};

