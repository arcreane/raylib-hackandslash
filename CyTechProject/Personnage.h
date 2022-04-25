#include "raylib.h"
#include "raymath.h"
#include "Dimension.h"

#pragma once
class Personnage {
private:
    Rectangle pos_dim;
    bool orientation;
    float speed;
    bool canJump;
public:
    void setPersonnage(Rectangle p, bool o, float s, bool cj);

    void setPosition(Vector2 p);
    void setX(float x);
    void setY(float y);
    void setXDroite(float x);
    void setYBas(float y);
    void setOrientation(bool b);
    void setSpeed(float s);
    void setCanJump(bool cj);

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

    //void seDeplacer();
};