#include "Animation_Ghost.h"

void Animation_Ghost::Init_animation_ghost()
{
    this->frameRecDroite = { 112.0f, -115.0f, 32, 28 };
    this->frameRecGauche = { 112.0f, -115.0f, -32, 28 };

    this->RunGhost0 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ghost/idle00.png");
    this->RunGhost1 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ghost/idle01.png");
    this->RunGhost2 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ghost/idle02.png");
    this->RunGhost3 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ghost/idle03.png");
}

void Animation_Ghost::animation_run_droite(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->RunGhost0, this->frameRecDroite, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->RunGhost1, this->frameRecDroite, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->RunGhost2, this->frameRecDroite, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->RunGhost3, this->frameRecDroite, position, WHITE);
}



void Animation_Ghost::animation_run_gauche(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->RunGhost0, this->frameRecGauche, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->RunGhost1, this->frameRecGauche, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->RunGhost2, this->frameRecGauche, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->RunGhost3, this->frameRecGauche, position, WHITE);
}