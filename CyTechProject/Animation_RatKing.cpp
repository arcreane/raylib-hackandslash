#include "Animation_RatKing.h"

void Animation_RatKing::Init_animation_ratKing()
{
    this->frameRecDroite = { 112.0f, -119.0f, 33, 48 };
    this->frameRecGauche = { 112.0f, -119.0f, -33, 48 };

    this->RunRatKing0 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing00.png");
    this->RunRatKing1 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing01.png");
    this->RunRatKing2 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing02.png");
    this->RunRatKing3 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing03.png");
    this->RunRatKing4 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing04.png");
    this->RunRatKing5 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing05.png");
    this->RunRatKing6 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing06.png");
    this->RunRatKing7 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing07.png");
    this->RunRatKing8 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing08.png");
    this->RunRatKing9 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing09.png");
    this->RunRatKing10 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing10.png");
    this->RunRatKing11 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing11.png");
    this->RunRatKing12 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing12.png");
    this->RunRatKing13 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing13.png");
    this->RunRatKing14 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing14.png");
    this->RunRatKing15 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/ratKing/ratKing15.png");
}

void Animation_RatKing::animation_run_droite(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->RunRatKing0, this->frameRecDroite, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->RunRatKing1, this->frameRecDroite, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->RunRatKing2, this->frameRecDroite, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->RunRatKing3, this->frameRecDroite, position, WHITE);
    if (currentFrame == 4) DrawTextureRec(this->RunRatKing4, this->frameRecDroite, position, WHITE);
    if (currentFrame == 5) DrawTextureRec(this->RunRatKing5, this->frameRecDroite, position, WHITE);
    if (currentFrame == 6) DrawTextureRec(this->RunRatKing6, this->frameRecDroite, position, WHITE);
    if (currentFrame == 7) DrawTextureRec(this->RunRatKing7, this->frameRecDroite, position, WHITE);
    if (currentFrame == 8) DrawTextureRec(this->RunRatKing8, this->frameRecDroite, position, WHITE);
    if (currentFrame == 9) DrawTextureRec(this->RunRatKing9, this->frameRecDroite, position, WHITE);
    if (currentFrame == 10) DrawTextureRec(this->RunRatKing10, this->frameRecDroite, position, WHITE);
    if (currentFrame == 11) DrawTextureRec(this->RunRatKing11, this->frameRecDroite, position, WHITE);
    if (currentFrame == 12) DrawTextureRec(this->RunRatKing12, this->frameRecDroite, position, WHITE);
    if (currentFrame == 13) DrawTextureRec(this->RunRatKing13, this->frameRecDroite, position, WHITE);
    if (currentFrame == 14) DrawTextureRec(this->RunRatKing14, this->frameRecDroite, position, WHITE);
    if (currentFrame == 15) DrawTextureRec(this->RunRatKing15, this->frameRecDroite, position, WHITE);
}



void Animation_RatKing::animation_run_gauche(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->RunRatKing0, this->frameRecGauche, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->RunRatKing1, this->frameRecGauche, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->RunRatKing2, this->frameRecGauche, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->RunRatKing3, this->frameRecGauche, position, WHITE);
    if (currentFrame == 4) DrawTextureRec(this->RunRatKing4, this->frameRecGauche, position, WHITE);
    if (currentFrame == 5) DrawTextureRec(this->RunRatKing5, this->frameRecGauche, position, WHITE);
    if (currentFrame == 6) DrawTextureRec(this->RunRatKing6, this->frameRecGauche, position, WHITE);
    if (currentFrame == 7) DrawTextureRec(this->RunRatKing7, this->frameRecGauche, position, WHITE);
    if (currentFrame == 8) DrawTextureRec(this->RunRatKing8, this->frameRecGauche, position, WHITE);
    if (currentFrame == 9) DrawTextureRec(this->RunRatKing9, this->frameRecGauche, position, WHITE);
    if (currentFrame == 10) DrawTextureRec(this->RunRatKing10, this->frameRecGauche, position, WHITE);
    if (currentFrame == 11) DrawTextureRec(this->RunRatKing11, this->frameRecGauche, position, WHITE);
    if (currentFrame == 12) DrawTextureRec(this->RunRatKing12, this->frameRecGauche, position, WHITE);
    if (currentFrame == 13) DrawTextureRec(this->RunRatKing13, this->frameRecGauche, position, WHITE);
    if (currentFrame == 14) DrawTextureRec(this->RunRatKing14, this->frameRecGauche, position, WHITE);
    if (currentFrame == 15) DrawTextureRec(this->RunRatKing15, this->frameRecGauche, position, WHITE);
}