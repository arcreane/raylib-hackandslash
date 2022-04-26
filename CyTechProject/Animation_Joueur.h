#include "raylib.h"
#pragma once
class Animation_Joueur
{
private:
	Texture2D RunLoop0, RunLoop1, RunLoop2, RunLoop3, RunLoop4, RunLoop5;
	Texture2D Immobile0, Immobile1, Immobile2, Immobile3, Immobile4, Immobile5, Immobile6;
	Rectangle frameRecDroite;
	Rectangle frameRecGauche;
public:
	void Init_animation_joueur();
	void animation_run_gauche(Vector2 position, int currentFrame);
	void animation_immobile(Vector2 position, int currentFrame);
	void animation_run_droite(Vector2 position, int currentFrame);
};

