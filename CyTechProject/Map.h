#include"Platform.h"
#include"Item.h"
#include"Ghost.h"
#include"RatKing.h"
#include"raylib.h"
#include <vector>

#pragma once
#define NB_MAX_PLATFORM 20
#define NB_MAX_BOX 20

class Map
{
private :
	std::vector<Platform> platforms;
	std::vector<Mob* > mobs;
	std::vector<Platform> boxes;
	std::vector<Item* > items;
	Texture2D background;
	Rectangle spawn;
public :
	Map(Texture2D bg);
	Map();
	~Map();
	void setMap(Texture2D bg);
	void afficheBackground();
	void addPlatformMap(Rectangle rec);
	void addBoxMap(Rectangle rec);
	void addMobMap(Mob* mob);
	void addItemMap(Item* mob);
	void setSpawn(Rectangle rectangle);
	Rectangle getSpawn();
	std::vector<Platform> getPlatforms();
	std::vector<Platform> getBoxes();
	std::vector<Mob*> getMobs();
	std::vector<Item*> getItems();
	Mob* getMob(int i);
	Item* getItem(int i);
};

