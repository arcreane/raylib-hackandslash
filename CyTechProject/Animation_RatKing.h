#pragma once
#include "raylib.h"
class Animation_RatKing
{
private:
	Texture2D RunRatKing0, RunRatKing1, RunRatKing2, RunRatKing3, RunRatKing4, RunRatKing5, RunRatKing6, RunRatKing7, RunRatKing8, RunRatKing9, RunRatKing10, RunRatKing11, RunRatKing12, RunRatKing13, RunRatKing14, RunRatKing15;

	Rectangle frameRecDroite;
	Rectangle frameRecGauche;

public:
	void Init_animation_ratKing();
	void animation_run_droite(Vector2 position, int currentFrame);
	void animation_run_gauche(Vector2 position, int currentFrame);
};

