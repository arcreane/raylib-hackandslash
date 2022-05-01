#include "Arme.h"
#include "Item.h"

#pragma once
class DeathTouch : public Arme, public Item
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
	void setPossetion(bool p);

	Rectangle getRectangle();
	Vector2 getPosition();
	bool getActive();
	float getX();
	float getY();
	bool possetion();

	// class portail
	/*
	DeathTouch(Rectangle rec);
	void setItem(Rectangle rec);
	Item* copy() override;
	*/
};

