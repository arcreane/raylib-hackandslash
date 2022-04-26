#include "Animation_Joueur.h"
#include "raylib.h"

void Animation_Joueur::Init_animation_joueur()
{
    this->frameRecDroite = { 112.0f, -119.0f, 56, 40 };
    this->frameRecGauche = { 112.0f, -119.0f, -56, 40 };
    this->RunLoop1 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/runLoop01.png");
    this->RunLoop0 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/runLoop00.png");
    this->RunLoop2 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/runLoop02.png");
    this->RunLoop3 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/runLoop03.png");
    this->RunLoop4 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/runLoop04.png");
    this->RunLoop5 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/runLoop05.png");

}
void Animation_Joueur::animation_run_droite(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->RunLoop0, this->frameRecDroite, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->RunLoop1, this->frameRecDroite, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->RunLoop2, this->frameRecDroite, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->RunLoop3, this->frameRecDroite, position, WHITE);
    if (currentFrame == 4) DrawTextureRec(this->RunLoop4, this->frameRecDroite, position, WHITE);
    if (currentFrame == 5) DrawTextureRec(this->RunLoop5, this->frameRecDroite, position, WHITE);
}

void Animation_Joueur::animation_run_gauche(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->RunLoop0, this->frameRecGauche, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->RunLoop1, this->frameRecGauche, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->RunLoop2, this->frameRecGauche, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->RunLoop3, this->frameRecGauche, position, WHITE);
    if (currentFrame == 4) DrawTextureRec(this->RunLoop4, this->frameRecGauche, position, WHITE);
    if (currentFrame == 5) DrawTextureRec(this->RunLoop5, this->frameRecGauche, position, WHITE);
}

