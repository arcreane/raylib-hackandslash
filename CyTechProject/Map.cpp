#include "Map.h"

Map::Map(Texture2D bg) {
	background = bg;
}

void Map::setMap(Texture2D bg) {
	background = bg;
}

void Map::afficheBackground() {
	DrawTexture(this->background, 0, 0, WHITE);
}

void Map::addPlatformMap(Rectangle rec) {
	this->platforms.push_back(Platform(rec));
}
void Map::addBoxMap(Rectangle rec) {
	this->boxes.push_back(Platform(rec));
}

Map::Map(){}

std::vector<Platform> Map::getPlatforms() {
	return platforms;
}

std::vector<Platform> Map::getBoxes() {
	return boxes;
}

std::vector<Mob*> Map::getMobs() {
	return mobs;
}

Mob* Map::getMob(int i) {
	return mobs[i];
}

std::vector<Item*> Map::getItems() {
	return items;
}

Item* Map::getItem(int i) {
	return items[i];
}

void Map::addMobMap(Mob* mob) {
	mobs.push_back(mob);
}

void Map::addItemMap(Item* item) {
	items.push_back(item);
}

void Map::setSpawn(Rectangle rectangle)
{
	this->spawn = rectangle;
}

Rectangle Map::getSpawn()
{
	return this->spawn;
}

Map::~Map() {
	for (unsigned i = 0; i < mobs.size(); i++) {
		delete mobs[i];
	}
}