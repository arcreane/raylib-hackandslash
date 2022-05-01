#pragma once
#include "raylib.h"

class Animation_Ghost
{
private:
	Texture2D RunGhost0, RunGhost1, RunGhost2, RunGhost3;

	Rectangle frameRecDroite;
	Rectangle frameRecGauche;

public:
	void Init_animation_ghost();
	void animation_run_droite(Vector2 position, int currentFrame);
	void animation_run_gauche(Vector2 position, int currentFrame);
};

