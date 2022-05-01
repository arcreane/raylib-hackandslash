#pragma once
#include "raylib.h"

class Animation_Scythe
{
private:
	Texture2D Loop0, Loop1, Loop2, Loop3, Loop4, Loop5, Loop6, Loop7;
	Texture2D Item;


	Rectangle frameRecDroite;
	Rectangle frameRecGauche;

public:
	void Init_animation_scythe();
	void animation_loop_droite(Vector2 position, int currentFrame);
	void animation_loop_gauche(Vector2 position, int currentFrame);

	void drawItem(Vector2 position, Color c);


};

