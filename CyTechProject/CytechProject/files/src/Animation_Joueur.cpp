#include "../includes/Animation_Joueur.h"
#include "raylib.h"

void Animation_Joueur::Init_animation_joueur()
{
    this->frameRecDroite = { 112.0f, -119.0f, 34, 40 };
    this->frameRecGauche = { 112.0f, -119.0f, -34, 40 };
    this->frameRecDroiteAttaque = { 112.0f, -119.0f, 134, 40 };
    this->frameRecGaucheAttaque = { 112.0f, -119.0f, -134, 40 };

    this->RunLoop0 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/runLoop00.png");
    this->RunLoop1 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/runLoop01.png");
    this->RunLoop2 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/runLoop02.png");
    this->RunLoop3 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/runLoop03.png");
    this->RunLoop4 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/runLoop04.png");
    this->RunLoop5 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/runLoop05.png");
    
    this->Immobile0 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/timeOut00.png");
    this->Immobile1 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/timeOut01.png");
    this->Immobile2 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/timeOut02.png");
    this->Immobile3 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/timeOutLookUp00.png");
    this->Immobile4 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/timeOutLookUp01.png");
    this->Immobile5 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/timeOutLookUp02.png");
    this->Immobile6 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/timeOutLookUp03.png");

    this->Jump0 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/jumpFlip200.png");
    this->Jump1 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/jumpFlip201.png");
    this->Jump2 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/jumpFlip202.png");
    this->Jump3 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/jumpFlip203.png");
    this->Jump4 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/jumpFlip204.png");
    this->Jump5 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/jumpFlip205.png");
    this->Jump6 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/jumpFlip206.png");

    this->Attaque0 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/ladderSlashFire00.png");
    this->Attaque1 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/ladderSlashFire01.png");
    this->Attaque2 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/ladderSlashFire02.png");
    this->Attaque3 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/ladderSlashFire03.png");
    this->Attaque4 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/ladderSlashFire04.png");
    this->Attaque5 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/joueur/ladderSlashFire05.png");
   


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

void Animation_Joueur::animation_immobile_droite(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->Immobile0, this->frameRecDroite, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->Immobile1, this->frameRecDroite, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->Immobile2, this->frameRecDroite, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->Immobile3, this->frameRecDroite, position, WHITE);
    if (currentFrame == 4) DrawTextureRec(this->Immobile4, this->frameRecDroite, position, WHITE);
    if (currentFrame == 5) DrawTextureRec(this->Immobile5, this->frameRecDroite, position, WHITE);
    if (currentFrame == 6) DrawTextureRec(this->Immobile6, this->frameRecDroite, position, WHITE);
}

void Animation_Joueur::animation_immobile_gauche(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->Immobile0, this->frameRecGauche, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->Immobile1, this->frameRecGauche, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->Immobile2, this->frameRecGauche, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->Immobile3, this->frameRecGauche, position, WHITE);
    if (currentFrame == 4) DrawTextureRec(this->Immobile4, this->frameRecGauche, position, WHITE);
    if (currentFrame == 5) DrawTextureRec(this->Immobile5, this->frameRecGauche, position, WHITE);
    if (currentFrame == 6) DrawTextureRec(this->Immobile6, this->frameRecGauche, position, WHITE);
}



void Animation_Joueur::animation_jump_droite(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->Jump0, this->frameRecDroite, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->Jump1, this->frameRecDroite, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->Jump2, this->frameRecDroite, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->Jump3, this->frameRecDroite, position, WHITE);
    if (currentFrame == 4) DrawTextureRec(this->Jump4, this->frameRecDroite, position, WHITE);
    if (currentFrame == 5) DrawTextureRec(this->Jump5, this->frameRecDroite, position, WHITE);
    if (currentFrame == 6) DrawTextureRec(this->Jump6, this->frameRecDroite, position, WHITE);
}

void Animation_Joueur::animation_jump_gauche(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->Jump0, this->frameRecGauche, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->Jump1, this->frameRecGauche, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->Jump2, this->frameRecGauche, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->Jump3, this->frameRecGauche, position, WHITE);
    if (currentFrame == 4) DrawTextureRec(this->Jump4, this->frameRecGauche, position, WHITE);
    if (currentFrame == 5) DrawTextureRec(this->Jump5, this->frameRecGauche, position, WHITE);
    if (currentFrame == 6) DrawTextureRec(this->Jump6, this->frameRecGauche, position, WHITE);
}


void Animation_Joueur::animation_attaque_droite(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->Attaque0, this->frameRecDroiteAttaque, {position.x +1, position.y}, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->Attaque1, this->frameRecDroiteAttaque, {position.x +1, position.y}, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->Attaque2, this->frameRecDroiteAttaque, {position.x +1, position.y}, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->Attaque3, this->frameRecDroiteAttaque, {position.x +1, position.y}, WHITE);
    if (currentFrame == 4) DrawTextureRec(this->Attaque4, this->frameRecDroiteAttaque, {position.x +1, position.y}, WHITE);
    if (currentFrame >= 5 || currentFrame == -1) DrawTextureRec(this->Attaque5, this->frameRecDroiteAttaque, {position.x +1, position.y}, WHITE);
}

void Animation_Joueur::animation_attaque_gauche(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->Attaque0, this->frameRecGaucheAttaque, {position.x -105, position.y}, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->Attaque1, this->frameRecGaucheAttaque, {position.x -105, position.y}, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->Attaque2, this->frameRecGaucheAttaque, {position.x -105, position.y}, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->Attaque3, this->frameRecGaucheAttaque, {position.x -105, position.y}, WHITE);
    if (currentFrame == 4) DrawTextureRec(this->Attaque4, this->frameRecGaucheAttaque, {position.x -105, position.y}, WHITE);
    if (currentFrame >= 5 || currentFrame == -1) DrawTextureRec(this->Attaque5, this->frameRecGaucheAttaque, {position.x -105, position.y}, WHITE);
}