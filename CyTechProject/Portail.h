#include "Item.h"

#pragma once

class Portail : public Item
{
public:
	Portail(Rectangle rec);
	void setItem(Rectangle rec);
	Item* copy() override;
};

