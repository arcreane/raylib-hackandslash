#include "Item.h"

#pragma once

class Portail : public Item
{
public:
	Portail(Rectangle rec, std::string type);
	void setItem(Rectangle rec);
	Item* copy() override;
};

