#include "../includes/Animation_Scythe.h"

void Animation_Scythe::Init_animation_scythe()
{
    this->frameRecDroite = { 105.0f, -137.0f, -68, 68 };
    this->frameRecGauche = { 105.0f, -137.0f, 68, 68 };
    this->Loop0 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/items/scythe/scytheLargeSpin00.png");
    this->Loop1 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/items/scythe/scytheLargeSpin01.png");
    this->Loop2 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/items/scythe/scytheLargeSpin02.png");
    this->Loop3 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/items/scythe/scytheLargeSpin03.png");
    this->Loop4 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/items/scythe/scytheLargeSpin04.png");
    this->Loop5 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/items/scythe/scytheLargeSpin05.png");
    this->Loop6 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/items/scythe/scytheLargeSpin06.png");
    this->Loop7 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/items/scythe/scytheLargeSpin07.png");

    this->Item = LoadTexture("../CyTechProject/CyTechProject/files/ressources/items/scythe/scythe00.png");
}


void Animation_Scythe::animation_loop_droite(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->Loop0, this->frameRecDroite, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->Loop1, this->frameRecDroite, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->Loop2, this->frameRecDroite, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->Loop3, this->frameRecDroite, position, WHITE);
    if (currentFrame == 4) DrawTextureRec(this->Loop4, this->frameRecDroite, position, WHITE);
    if (currentFrame == 5) DrawTextureRec(this->Loop5, this->frameRecDroite, position, WHITE);
    if (currentFrame == 6) DrawTextureRec(this->Loop6, this->frameRecDroite, position, WHITE);
    if (currentFrame == 7) DrawTextureRec(this->Loop7, this->frameRecDroite, position, WHITE);
}

void Animation_Scythe::animation_loop_gauche(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->Loop0, this->frameRecGauche, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->Loop1, this->frameRecGauche, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->Loop2, this->frameRecGauche, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->Loop3, this->frameRecGauche, position, WHITE);
    if (currentFrame == 4) DrawTextureRec(this->Loop4, this->frameRecGauche, position, WHITE);
    if (currentFrame == 5) DrawTextureRec(this->Loop5, this->frameRecGauche, position, WHITE);
    if (currentFrame == 6) DrawTextureRec(this->Loop6, this->frameRecGauche, position, WHITE);
    if (currentFrame == 7) DrawTextureRec(this->Loop7, this->frameRecGauche, position, WHITE);
}

void Animation_Scythe::drawItem(Vector2 position, Color c) {
    DrawTextureRec(this->Item, this->frameRecDroite, position, c);
}
