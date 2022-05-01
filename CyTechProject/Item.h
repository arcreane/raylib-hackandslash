#include "Joueur.h"
#include <string>


#pragma once
class Item
{
protected:
	std::string type;
	Rectangle hitBox;
public:
	Rectangle getRectangle();
	std::string getType();
	Item(Rectangle rec, std::string type);
	Item(Rectangle rec);
	Item();
	virtual Item* copy();
	float getX();
	float getY();
	void setItem(Rectangle rec);
};

