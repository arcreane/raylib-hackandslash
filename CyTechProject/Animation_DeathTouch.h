#pragma once
#include "raylib.h"
class Animation_DeathTouch
{
private:
	Texture2D Loop0, Loop1;


	Rectangle frameRecDroite;
	Rectangle frameRecGauche;

public:
	void Init_animation_deathTouch();
	void animation_loop_droite(Vector2 position, int currentFrame);
	void animation_loop_gauche(Vector2 position, int currentFrame);

};

