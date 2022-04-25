#include "raylib.h"
#include "raymath.h"
#include "Dimension.h"

#pragma once
class Personnage {
protected:
    Rectangle pos_dim;
    bool orientation;
    float speed;
    bool canJump;
    bool isAlive;

public:
    void setPersonnage(Rectangle p);

    void setPosition(Vector2 p);
    void setX(float x);
    void setY(float y);
    void setXDroite(float x);
    void setYBas(float y);
    void setOrientation(bool b);
    void setSpeed(float s);
    void setCanJump(bool cj);
    void setIsAlive(bool ia);

    Rectangle getRectangle();
    Vector2 getPosition();
    float getX();
    float getY();
    float getXDroite();
    float getYBas();
    bool getOrientation();
    float getSpeed();
    bool getCanJump();
    Dimension getDimension();
    float getWidth();
    float getHeight();
    bool getIsAlive();

    //void seDeplacer();
};