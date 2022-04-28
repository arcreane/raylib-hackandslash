#include "mobPath1.h"

MobPath1::MobPath1(Rectangle rec, bool o, float d, float a) {
    pos_dim = rec;
    orientation = o;
    dep = d;
    arr = a;
    RunZombie0 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/zombie/walk00.png");
    RunZombie1 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/zombie/walk01.png");
    RunZombie2 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/zombie/walk02.png");
    RunZombie3 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/zombie/walk03.png");
    this->frameRecDroite = { 112.0f, -119.0f, 34, 40 };
    this->frameRecGauche = { 112.0f, -119.0f, -34, 40 };

}

void MobPath1::setMob(Rectangle rec, bool o, float d, float a) {
    this->pos_dim = rec;
    this->orientation = o;
    this->dep = d;
    this->arr = a;
    frameRecDroite = { 112.0f, -119.0f, 34, 40 };
    frameRecGauche = { 112.0f, -119.0f, -34, 40 };

}

void MobPath1::setOrientation(bool o)
{
    this->orientation = o;
}

bool MobPath1::getOrientation()
{
    return this->orientation;
}

void MobPath1::pathMob(Joueur player)
{
    if (this->orientation) {
        this->setX(this->getX() + 1);
        if (this->getX() > this->arr) {
            this->setOrientation(false);
        }
    }
    else {
        this->setX(this->getX() - 1);
        if (this->getX() < this->dep) {
            this->setOrientation(true);
        }
    }
}

/*void MobPath1::Init_animation_zombie()
{
    this->frameRecDroite = { 112.0f, -119.0f, 34, 40 };
    this->frameRecGauche = { 112.0f, -119.0f, -34, 40 };

    this->RunZombie0 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/zombie/walk00.png");
    this->RunZombie1 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/zombie/walk01.png");
    this->RunZombie2 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/zombie/walk02.png");
    this->RunZombie3 = LoadTexture("../CyTechProject/CyTechProject/files/ressources/animations/zombie/walk03.png");
}*/

void MobPath1::animation_run_droite(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->RunZombie0, this->frameRecDroite, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->RunZombie1, this->frameRecDroite, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->RunZombie2, this->frameRecDroite, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->RunZombie3, this->frameRecDroite, position, WHITE);
}   

void MobPath1::animation_run_gauche(Vector2 position, int currentFrame)
{
    if (currentFrame == 0) DrawTextureRec(this->RunZombie0, this->frameRecGauche, position, WHITE);
    if (currentFrame == 1) DrawTextureRec(this->RunZombie1, this->frameRecGauche, position, WHITE);
    if (currentFrame == 2) DrawTextureRec(this->RunZombie2, this->frameRecGauche, position, WHITE);
    if (currentFrame == 3) DrawTextureRec(this->RunZombie3, this->frameRecGauche, position, WHITE);
}
