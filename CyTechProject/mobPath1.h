#include "Mob.h"

#pragma once
class MobPath1 : public Mob
{
private:
	float dep;
	float arr;
	/*Texture2D RunZombie0, RunZombie1, RunZombie2, RunZombie3;

	Rectangle frameRecDroite;
	Rectangle frameRecGauche;*/
public:
	MobPath1(Rectangle rec, bool o, float d, float a);
	void setMob(Rectangle rec, bool o, float d, float a) override; 
	void pathMob(Joueur player) override;
	//void Init_animation_zombie();
	//void animation_run_droite(Vector2 position, int currentFrame) override;
	//void animation_run_gauche(Vector2 position, int currentFrame) override;
};

