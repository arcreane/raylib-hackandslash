#include "../includes/Item.h"

Rectangle Item::getRectangle()
{
    return this->hitBox;
}

std::string Item::getType()
{
    return this->type;
}

Item::Item(Rectangle rec, std::string type)
{
    hitBox = rec;
    this->type = type;
}

Item::Item(Rectangle rec) {
    hitBox = rec;
}

Item::Item() {
    hitBox = { 0,0,0,0 };
}

float Item::getX()
{
    return this->hitBox.x;
}

float Item::getY()
{
    return this->hitBox.y;
}

void Item::setItem(Rectangle rec) {
    this->hitBox = rec;
}

Item* Item::copy() {
    return new Item(this->hitBox, this->type);
}