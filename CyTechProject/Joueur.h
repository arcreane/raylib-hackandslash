#include "Personnage.h"

#pragma once
class Joueur : public Personnage
{
public:
	void updatePlayer(std::vector<Platform> platform, std::vector<Platform> box, float delta);
	void CheckCollisionPlatform(std::vector<Platform> platform, float delta);
	void CheckCollisionBlocPlein(std::vector<Platform> box, float delta);
};

