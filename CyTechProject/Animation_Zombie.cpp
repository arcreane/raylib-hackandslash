#include "Animation_Zombie.h"

void Animation_Zombie::Init_animation_zombie()
{
    this->frameRecDroite = { 112.0f, -119.0f, 34, 40 };
    this->frameRecGauche = { 112.0f, -119.0f, -34, 40 };

    this->RunZombie0 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/zombie/walk00.png");
    this->RunZombie1 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/zombie/walk01.png");
    this->RunZombie2 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/zombie/walk02.png");
    this->RunZombie3 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/zombie/walk03.png");
}

void Animation_Zombie::animation_run_droite(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->RunZombie0, this->frameRecDroite, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->RunZombie1, this->frameRecDroite, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->RunZombie2, this->frameRecDroite, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->RunZombie3, this->frameRecDroite, position, WHITE);
}



void Animation_Zombie::animation_run_gauche(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->RunZombie0, this->frameRecGauche, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->RunZombie1, this->frameRecGauche, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->RunZombie2, this->frameRecGauche, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->RunZombie3, this->frameRecGauche, position, WHITE);
}