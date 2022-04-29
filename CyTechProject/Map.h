#include"Platform.h"
#include"mobPath2.h"
#include"mobPath1.h"
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
	Texture2D background;
public :
	Map(Texture2D bg);
	Map();
	void setMap(Texture2D bg);
	void afficheBackground();
	void addPlatformMap(Rectangle rec);
	void addBoxMap(Rectangle rec);
	void addMobMap(Mob* mob);
	std::vector<Platform> getPlatforms();
	std::vector<Platform> getBoxes();
	std::vector<Mob*> getMobs();
	Mob* getMob(int i);
};

