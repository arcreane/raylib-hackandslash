#include "Item.h"

Rectangle Item::getRectangle()
{
    return this->hitBox;
}

std::string Item::getType()
{
    return this->type;
}

Item::Item(Rectangle rec) {
    hitBox = rec;
}

Item::Item() {
    hitBox = { 0,0,0,0 };
}

Item* Item::copy() {
    return new Item(this->hitBox);
}

float Item::getX()
{
    return this->hitBox.x;
}

float Item::getY()
{
    return this->hitBox.y;
}
