#include "Arme.h"
#include "Animation_DeathTouch.h"

#pragma once
class DeathTouch : public Arme, public Item
{
private:
	Rectangle hitBox;
	Rectangle positionItem;
	Map* _m;
	bool possede;
	bool active;
	Animation_DeathTouch item;
public:
	void setArme();
	void setOn(Vector2 pos, Map* m);
	void setOut();
	void setOff();
	void updatePositon();
	void updateArme(Joueur player, Map* m);
	void setPossetion(bool p);
	void resetTime();

	Rectangle getRectangle();
	Vector2 getPosition();
	bool getActive();
	float getX();
	float getY();
	bool possetion();
};

