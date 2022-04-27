#include "raylib.h"
#include "raymath.h"
#include "../../Platform.h"
#include "../../mobPath1.h"
#include "../../mobPath2.h"
#include "../../Arme.h"
#include "../../Animation_Joueur.h"
#include <vector>

//JB was here
//Henri is in your wall


#define G 1000
#define PLAYER_JUMP_SPD 550.0f
#define PLAYER_HOR_SPD 300.0f
#define FRAMES_SPEED 8
#define NB_PLATFORM 13
#define NB_MOB_PASSIF 3

const int screenWidth = 1600;
const int screenHeight = 900;
int currentFrame = 0;
int currentFrameImmobile = 0;
int framesCounter = 0;
int currentFrameAttaque = 0;

Joueur UpdatePlayer(Joueur player, Platform platform[NB_PLATFORM], Arme attaque, float delta);
Joueur CheckCollisionPlatform(Joueur player, Platform platform[NB_PLATFORM], float delta);
Arme UpdateArme(Joueur player, Arme arme);


int main(void)
{
    InitWindow(screenWidth, screenHeight, "Premier test");

#pragma region Initialisation

    Animation_Joueur animation_joueur;

    Joueur player;
    player.setPersonnage({ 300, 100, 28, 40 });

    Arme arme;
    arme.setArme({ 60, 40 }, 100, 50);

    std::vector<Mob* > mob;
    //input données
    mob.push_back(new MobPath1({ 750, 200, 50, 50 }, true, 700, 800));
    mob.push_back(new MobPath2({ 375, 600, 50, 50 }));
    mob.push_back(new MobPath1({ 375, 600, 50, 50 }, true, 300, 450));
    mob.push_back(new Mob({ 0,855,1600,5 }));

    Mob mobPassif[NB_MOB_PASSIF];
    mobPassif[0].setPersonnage({ 450, 300, 50, 50 });
    mobPassif[1].setPersonnage({ 0, 200, 50, 50 });
    mobPassif[2].setPersonnage({ 300, 600, 50, 50 });

    Texture2D background = LoadTexture("../CyTechProject/CyTechProject/files/ressources/map/map1.png");

    Platform platform[NB_PLATFORM];
    float a;
    platform[0].setPlatform({ 0, 405, 905, 10 });                        
    platform[1].setPlatform({ 0,227,268,10 });                            
    a = 1121;
    platform[2].setPlatform({ a,405,(screenWidth - a),10 });
    a = 1333;
    platform[3].setPlatform({ a,137,(screenWidth - a),10 });
    a = 1495;
    platform[4].setPlatform({ a,275,(screenWidth - a),10 });
    platform[5].setPlatform({ 430,93,315,10 });                           
    a = 1386;
    platform[6].setPlatform({ a, 630, (screenWidth - a), 10 });
    platform[7].setPlatform({ 963, 540, 318, 10 });
    platform[8].setPlatform({ 587, 676, 213, 10 });
    platform[9].setPlatform({ 415, 617, 70, 10 });
    platform[10].setPlatform({ 53, 631, 213, 10 });
    platform[11].setPlatform({ 0, 318, 48, 10 });
    platform[12].setPlatform({ 0, 363, 102, 10 });

    /*Platform platform[NB_PLATFORM];
    float a;
    platform[0].setPlatform({ 160, 855, 640, 10 });                         
    platform[1].setPlatform({ 0,138,316,10 });                           
    platform[2].setPlatform({ 0,271,209,10 });
    platform[3].setPlatform({ 0,407,52,10 });
    platform[4].setPlatform({ 0,495,905,10 });
    platform[5].setPlatform({ 693,450,212,10 });                      
    platform[6].setPlatform({ 745, 405, 54, 10 });
    platform[7].setPlatform({ 1067, 313, 1438 - 1067, 10 });
    platform[8].setPlatform({ 905, 541, 54, 10 });
    a = 906;
    platform[9].setPlatform({ a, 673, screenWidth - a, 10 });
    platform[10].setPlatform({ 800, 810, 54, 10 });
    platform[11].setPlatform({ 852, 764, 54, 10 });

    Texture2D background = LoadTexture("../CyTechProject/CyTechProject/files/ressources/map/map2.png");*/

    Camera2D camera = { 0 };
    camera.target = { 800, 450 };
    camera.offset.x = screenWidth / 2.0f;
    camera.offset.y = screenHeight / 2.0f;
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

#pragma region initAnim

    animation_joueur.Init_animation_joueur();
#pragma endregion initAnim

#pragma endregion initialisation

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

#pragma region MainGameLoop
    while (!WindowShouldClose())
    {
#pragma region Update
        //----------------------------------------------------------------------------------
        float deltaTime = GetFrameTime();

        DrawTexture(background, 0, 0, WHITE);

        //for (int i = 0; i < NB_PLATFORM; i++) DrawRectangleRec(platform[i].getRectangle(), GRAY);

        player = UpdatePlayer(player, platform, arme, deltaTime);

        

        for (int i = 0; i < NB_MOB_PASSIF; i++) {
            if (CheckCollisionRecs(player.getRectangle(), mobPassif[i].getRectangle()) && mobPassif[i].getIsAlive()) {
                mobPassif[i].setIsAlive(false);
            }

            if (mobPassif[i].getIsAlive()) {
                DrawRectangleRec(mobPassif[i].getRectangle(), GREEN);
            }
        }

        for (unsigned i = 0; i < mob.size(); i++) {
            if (CheckCollisionRecs(player.getRectangle(), mob[i]->getRectangle()) && mob[i]->getIsAlive()) {
                player.setIsAlive(false);
                player.setPersonnage({ 300, 100, 28, 40 });

                mob[0]->setMob({ 750, 200, 50, 50 }, true, 700, 800);
                mob[1]->setMob({ 500, 40, 50, 50 });
                mob[2]->setMob({ 375, 600, 50, 50 }, true, 300, 450);

                mobPassif[0].setPersonnage({ 450, 300, 50, 50 });
                mobPassif[1].setPersonnage({ 0, 200, 50, 50 });
                mobPassif[2].setPersonnage({ 300, 600, 50, 50 });
            }

            if (CheckCollisionRecs(arme.getRectangle(), mob[i]->getRectangle()) && arme.getActive() > 0 && arme.getEtat()) {
                mob[i]->setIsAlive(false);
            }

            if (mob[i]->getIsAlive()) {
                
                mob[i]->pathMob(player);
                Rectangle tmp = mob[i]->getRectangle();
                DrawRectangleRec(tmp, RED);
            }
        }

        if (arme.getEtat() == true) {
            if (arme.getDirection() == true) {
                arme.setOn({ player.getXDroite(), player.getY() });
            }
            else {
                arme.setOn({ player.getX() - arme.getWidth(), player.getY() });
            }
            arme.setCd();
            /*if (arme.getActive() > 0) {
                DrawRectangleRec(arme.getRectangle(), YELLOW);
            }*/
            if (arme.getCd() <= 0) {
                arme.setOff();
            }
        }

        if (IsKeyDown(KEY_J)) {
            if (IsKeyDown(KEY_K)) {
                if (IsKeyDown(KEY_I)) {
                    DrawRectangleRec({0,0,100,100}, PURPLE);
                }
            }
        }

#pragma region UpdateAnimation
        framesCounter++;

        if (framesCounter >= (60 / FRAMES_SPEED))
        {   
            framesCounter = 0;
            currentFrame++;
            currentFrameImmobile++;
            currentFrameAttaque ++;
            
            
            if (currentFrame > 5) currentFrame = 0;
            if (currentFrameImmobile > 6) currentFrameImmobile = 0;
            if (currentFrameAttaque > 6) currentFrameAttaque = 0;
        }
#pragma endregion UpdateAnimation

#pragma endregion Update

#pragma region Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(LIGHTGRAY);



        //DrawText("Test", 20, 20, 20, DARKGRAY);



        BeginMode2D(camera);

        Rectangle playerRect = { player.getPosition().x - (float)(player.getDimension().width / 2), player.getPosition().y - (float)player.getDimension().height, (float)player.getDimension().width, (float)player.getDimension().height };
        


#pragma region DrawAnimation

        if (IsKeyPressed(KEY_J) && !arme.getEtat())currentFrameAttaque = 0;
        if (arme.getCd()>0 && arme.getEtat() && arme.getActive()>0 && arme.getDirection())
            animation_joueur.animation_attaque_droite(player.getPosition(), currentFrameAttaque);
        if (arme.getCd()>0 && arme.getEtat() && arme.getActive()>0 && !arme.getDirection())
            animation_joueur.animation_attaque_gauche(player.getPosition(), currentFrameAttaque);
        if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT) && !player.getCanJump() && ((arme.getEtat() && arme.getActive() <= 0) || !arme.getEtat()))
            animation_joueur.animation_jump_droite(player.getPosition(), currentFrameImmobile);
        if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT) && !player.getCanJump() && ((arme.getEtat() && arme.getActive() <= 0) || !arme.getEtat()))
            animation_joueur.animation_jump_gauche(player.getPosition(), currentFrameImmobile);
        if (((!IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT)) || ((IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_LEFT)))) && player.getOrientation() && ((arme.getEtat() && arme.getActive() <= 0) || !arme.getEtat()))
            animation_joueur.animation_immobile_droite(player.getPosition(), currentFrameImmobile);
        if (((!IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT)) || ((IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_LEFT)))) && !player.getOrientation() && ((arme.getEtat() && arme.getActive() <= 0) || !arme.getEtat()))
            animation_joueur.animation_immobile_gauche(player.getPosition(), currentFrameImmobile);
        if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT) && player.getCanJump() && ((arme.getEtat() && arme.getActive() <= 0) || !arme.getEtat()))
            animation_joueur.animation_run_droite(player.getPosition(), currentFrame );
        if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT) && player.getCanJump() && ((arme.getEtat() && arme.getActive() <= 0) || !arme.getEtat()))
            animation_joueur.animation_run_gauche(player.getPosition(), currentFrame);

        arme = UpdateArme(player, arme);
#pragma endregion DrawAnimation

        EndMode2D();

        EndDrawing();
#pragma endregion Draw

    }
#pragma endregion MainGameLoop

    CloseWindow();        // Close window and OpenGL context

    //delete mob données
    for (unsigned i = 0; i < mob.size(); i++) {
        delete mob[i];
    }


    return 0;
}

Joueur UpdatePlayer(Joueur player, Platform platform[NB_PLATFORM], Arme arme, float delta)
{
    Dimension dim = player.getDimension();

    if (IsKeyDown(KEY_LEFT)) {
        player.setX(player.getX() - PLAYER_HOR_SPD * delta);
        player.setOrientation(false);
    }
    if (IsKeyDown(KEY_RIGHT)) {
        player.setX(player.getX() + PLAYER_HOR_SPD * delta);
        player.setOrientation(true);
    }
    if (IsKeyDown(KEY_UP) && player.getCanJump()) player.setSpeed(player.getSpeed() - PLAYER_JUMP_SPD);

    player.setY(player.getY() + player.getSpeed() * delta);
    player.setSpeed(player.getSpeed() + G * delta);
    player.setCanJump(false);

    if (player.getYBas() >= screenHeight)
    {
        player.setSpeed(0);
        player.setYBas(screenHeight);
        player.setCanJump(true);
    }

    if (player.getX() < 0) player.setX(0);
    if (player.getXDroite() > screenWidth) player.setXDroite((float)screenWidth);
    if (player.getY() < 0) {
        player.setSpeed(0);
        player.setY(0);
    }

    player = CheckCollisionPlatform(player, platform, delta);

    return player;
}

Joueur CheckCollisionPlatform(Joueur player, Platform platform[NB_PLATFORM], float delta) {
    for (int i = 0; i <= NB_PLATFORM; i++) {
        if (player.getX() >= platform[i].getXd() - player.getWidth() && player.getXDroite() <= platform[i].getXDroite() + player.getWidth()
            && player.getYBas() <= platform[i].getY() && (player.getYBas() + player.getSpeed() * delta) > platform[i].getY()) {
            player.setSpeed(0);
            player.setYBas(platform[i].getY());
            player.setCanJump(true);
        }
    }
    return player;
}

Arme UpdateArme(Joueur player, Arme arme) {
    if (IsKeyDown(KEY_J) && !arme.getEtat()) {
        if (player.getOrientation() == true) {
            arme.setOn({ player.getXDroite(), player.getY() });
            arme.setDirection(true);
        }
        if (player.getOrientation() == false) {
            arme.setOn({ player.getX() - arme.getWidth(), player.getY() });
            arme.setDirection(false);
        }
    }

    return arme;
}