#pragma once
#include "raylib.h"

class Animation_Zombie
{
private:
	Texture2D RunZombie0, RunZombie1, RunZombie2, RunZombie3;

	Rectangle frameRecDroite;
	Rectangle frameRecGauche;

public:
	void Init_animation_zombie();
	void animation_run_droite(Vector2 position, int currentFrame);
	void animation_run_gauche(Vector2 position, int currentFrame);

};

