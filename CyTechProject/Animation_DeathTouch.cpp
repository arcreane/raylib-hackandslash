#include "Animation_DeathTouch.h"


void Animation_DeathTouch::Init_animation_deathTouch()
{
    this->frameRecDroite = { 128.0f, -128.0f, 16, 48 };
    this->frameRecGauche = { 128.0f, -128.0f, -16, 48 };
    this->Loop0 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/items/deathTouch/deathTouchProjectile00.png");
    this->Loop1 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/items/deathTouch/deathTouchProjectile01.png");

}


void Animation_DeathTouch::animation_loop_droite(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->Loop0, this->frameRecDroite, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->Loop1, this->frameRecDroite, position, WHITE);

}

void Animation_DeathTouch::animation_loop_gauche(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->Loop0, this->frameRecGauche, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->Loop1, this->frameRecGauche, position, WHITE);

}
