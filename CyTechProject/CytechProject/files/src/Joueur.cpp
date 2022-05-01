#include "../includes/Joueur.h"

#define G 1000
#define PLAYER_JUMP_SPD 550.0f
#define PLAYER_HOR_SPD 300.0f


void Joueur::updatePlayer(std::vector<Platform> platform, std::vector<Platform> box, float delta)
{
    if (IsKeyDown(KEY_LEFT)) {

        this->setX(this->getX() - PLAYER_HOR_SPD * delta);
        this->setOrientation(false);
    }
    if (IsKeyDown(KEY_RIGHT)) {
        this->setX(this->getX() + PLAYER_HOR_SPD * delta);
        this->setOrientation(true);
    }
    if (IsKeyDown(KEY_UP) && this->getCanJump()) this->setSpeed(this->getSpeed() - PLAYER_JUMP_SPD);

    this->setY(this->getY() + this->getSpeed() * delta);
    this->setSpeed(this->getSpeed() + G * delta);
    this->setCanJump(false);

    if (this->getYBas() >= screenHeight)
    {
        this->setSpeed(0);
        this->setYBas(screenHeight);
        this->setCanJump(true);
    }

    if (this->getX() < 0) this->setX(0);
    if (this->getXDroite() > screenWidth) this->setXDroite((float)screenWidth);
    if (this->getY() < 0) {
        this->setSpeed(0);
        this->setY(0);
    }

    CheckCollisionPlatform(platform, delta);
    CheckCollisionBlocPlein(box, delta);
}

void Joueur::CheckCollisionPlatform(std::vector<Platform> platform, float delta) {
    for (int i = 0; i < platform.size(); i++) {
        if (this->getX() >= platform[i].getXd() - this->getWidth() && this->getXDroite() <= platform[i].getXDroite() + this->getWidth()
            && this->getYBas() <= platform[i].getY() && (this->getYBas() + this->getSpeed() * delta + 3) > platform[i].getY()) {
            this->setSpeed(0);
            this->setYBas(platform[i].getY());
            this->setCanJump(true);
        }
    }
}

void Joueur::CheckCollisionBlocPlein(std::vector<Platform> box, float delta) {
    for (int i = 0; i < box.size(); i++) {
        if (this->getXDroite() > box[i].getXd() && IsKeyDown(KEY_RIGHT) && this->getYBas() > box[i].getY() + 1 + G * delta && this->getY() < box[i].getYBas() - G * delta && this->getX() < box[i].getXDroite() - 1) this->setXDroite(box[i].getXd());
        if (this->getX() < box[i].getXDroite() && IsKeyDown(KEY_LEFT) && this->getYBas() > box[i].getY() + 1 + G * delta && this->getY() < box[i].getYBas() - G * delta && this->getXDroite() > box[i].getXd()) {
            this->setX(box[i].getXDroite());
        }

        if (this->getYBas() >= box[i].getY() && this->getX() < box[i].getXDroite() && this->getXDroite() > box[i].getXd() && this->getY() < box[i].getYBas() - G * delta)
        {
            if (this->getSpeed() >= 0) {
                this->setSpeed(0);
                this->setYBas(box[i].getY());
                this->setCanJump(true);
            }
        }

        if (this->getY() < box[i].getYBas() && this->getX() < box[i].getXDroite() && this->getXDroite() > box[i].getXd() && this->getYBas() > box[i].getY() + 20)
        {
            if (this->getSpeed()) {
                this->setSpeed(0);
                this->setY(box[i].getYBas());
            }
        }
    }
}