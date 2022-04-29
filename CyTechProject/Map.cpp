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

void Map::addMobMap(Mob* mob) {
	mobs.push_back(mob);
}

