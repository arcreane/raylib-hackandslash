#include "raylib.h"
#include "raymath.h"
#include "../../Joueur.h"
#include "../../Platform.h"
#include "../../ArmeCAC.h"
#include "../../ArmeDistance.h"
#include "../../DeathTouch.h"
#include "../../RatKing.h"
#include "../../Zombie.h"
#include "../../Ghost.h"
#include "../../Lave.h"
#include "../../Arme.h"
#include "../../Animation_Joueur.h"
#include "../../Map.h"
#include "../../Animation_Zombie.h"
#include "../../Animation_Ghost.h"
#include "../../Animation_RatKing.h"
#include "../../Animation_Scythe.h"
#include "../../Animation_DeathTouch.h"
#include "../../audio.h"
#include "../../Struct.h"
#include <vector>
#include <string>


//JB was here
//Henri is in your wall


#define FRAMES_SPEED 8
#define NB_MOB_PASSIF 3

int currentFrame = 0;
int currentFrameImmobile = 0;
int framesCounter = 0;
int currentFrameAttaque = 0;
int currentFrameZombie = 0;
int currentFrameRatKing = 0;
int currentFrameScythe = 0;
int currentFrameDeathTouch = 0;


int main(void)
{
    InitWindow(screenWidth, screenHeight, "Jeu Vidéo GAMING");

#pragma region Initialisation

    Animation_RatKing animation_ratKing;
    Animation_Joueur animation_joueur;
    Animation_Zombie animation_zombie;
    Animation_Ghost animation_ghost;
    Animation_Scythe animation_scythe;
    Animation_DeathTouch animation_deathTouch;

    Audio audio;

    Joueur player;
    player.setPersonnage({ 300, 100, 28, 40 });

    ArmeCAC arme;
    arme.setArme({ 60, 40 }, 70, 35);
    ArmeDistance item;
    item.setArme(34);



    Map maps[6];

    Mob mobPassif[NB_MOB_PASSIF];
    mobPassif[0].setPersonnage({ 450, 300, 50, 50 });
    mobPassif[1].setPersonnage({ 0, 200, 50, 50 });
    mobPassif[2].setPersonnage({ 300, 600, 50, 50 });


    //      Map 1
    //  Load Background
    maps[1].setMap(LoadTexture("../CyTechProject/CyTechProject/files/ressources/map/map1.png"));
    //  Platforms
    float a;
    maps[1].addPlatformMap({ 0, 405, 905, 10 });
    maps[1].addPlatformMap({ 0,227,268,10 });
    a = 1121;
    maps[1].addPlatformMap({ a,405,(screenWidth - a),10 });
    a = 1333;
    maps[1].addPlatformMap({ a,137,(screenWidth - a),10 });
    a = 1495;
    maps[1].addPlatformMap({ a,275,(screenWidth - a),10 });
    maps[1].addPlatformMap({ 430,93,315,10 });
    a = 1386;
    maps[1].addPlatformMap({ a, 630, (screenWidth - a), 10 });
    maps[1].addPlatformMap({ 963, 540, 318, 10 });
    maps[1].addPlatformMap( { 587, 676, 213, 10 });
    maps[1].addPlatformMap( { 415, 617, 70, 10 });
    maps[1].addPlatformMap( { 53, 631, 213, 10 });
    maps[1].addPlatformMap( { 0, 318, 48, 10 });
    maps[1].addPlatformMap( { 0, 363, 102, 10 });
    //  Boxes
    maps[1].addBoxMap({ 0,315,54,45 });
    maps[1].addBoxMap({ 0,359,54,45 });
    maps[1].addBoxMap({ 54,359,54,45 });
    //  Mobs depart et type
    maps[1].addMobMap(new RatKing({ 750, 200, 33, 48 }, true, 700, 800));
    maps[1].addMobMap(new Ghost({ 500, 40, 32, 28 }));
    maps[1].addMobMap(new RatKing({ 375, 600, 33, 48 }, true, 300, 450));
    maps[1].addMobMap(new Lave({ 0,855,1600,5 }));
    maps[1].addMobMap(new Zombie({ 577,1,34,40 }, true, &maps[1]));
    maps[1].addMobMap(new Zombie({ 1100,60,34,40 }, true, &maps[1]));

    DeathTouch deathTouch;
    deathTouch.setArme();

    //      Map 2
    //  Load Background
    maps[2].setMap(LoadTexture("../CyTechProject/CyTechProject/files/ressources/map/map2.png"));
    //  Platforms
    maps[2].addPlatformMap({ 160, 855, 640, 10 });
    maps[2].addPlatformMap({ 0,138,316,10 });
    maps[2].addPlatformMap({ 0,271,209,10 });
    maps[2].addPlatformMap({ 0,407,52,10 });
    maps[2].addPlatformMap({ 0,495,905,10 });
    maps[2].addPlatformMap({ 693,450,212,10 });
    maps[2].addPlatformMap({ 745, 405, 54, 10 });
    maps[2].addPlatformMap({ 1067, 313, 1438 - 1067, 10 });
    maps[2].addPlatformMap({ 905, 541, 54, 10 });
    a = 906;
    //maps[2].addPlatformMap({ a, 673, screenWidth - a, 10 });
    maps[2].addPlatformMap({ 800, 810, 54, 10 });
    maps[2].addPlatformMap({ 852, 764, 54, 10 });
    //  Boxes
    maps[2].addBoxMap({ 150,676,10,180 });
    maps[2].addBoxMap({ 160,666,266,10 });
    maps[2].addBoxMap({ 734,496,170,90 });
    maps[2].addBoxMap({ 693,451,210,40 });
    maps[2].addBoxMap({ 746,404,52,44 });
    maps[2].addBoxMap({ 798,810,10,44 });
    maps[2].addBoxMap({ 854,764,10,44 });
    a = 906;
    maps[2].addBoxMap({ a,673,screenWidth - a,88 });
    //  Mobs depart et type
    maps[2].addMobMap(new Lave({ 0,855,1600,5 }));
    maps[2].addMobMap(new Ghost({ 500, 40, 32, 28 }));

    //      Map 3
    //  Load Background
    maps[3].setMap(LoadTexture("../CyTechProject/CyTechProject/files/ressources/map/map3.png"));
    //  Platforms
    maps[3].addPlatformMap({ 0, 180, 317, 10 });
    maps[3].addPlatformMap({ 0,315,531,10 });
    maps[3].addPlatformMap({ 0,448,1013,10 });
    maps[3].addPlatformMap({ 0,855,1600,10 });
    maps[3].addPlatformMap({ 482,138,476,10 });
    a = 1226;
    maps[3].addPlatformMap({ a,450,1600 - a,10 });
    maps[3].addPlatformMap({ 803,585,689,10 });
    maps[3].addPlatformMap({ 630,707,70,10 });
    //  Boxes
    maps[3].addBoxMap({ 0,675,106,44 });
    maps[3].addBoxMap({ 0,720,160,44 });
    maps[3].addBoxMap({ 0,765,320,44 });
    maps[3].addBoxMap({ 0,810,480,44 });
    maps[3].addBoxMap({ 1494,361,53,44 });
    maps[3].addBoxMap({ 1440,406,106,44 });
    //  Mobs depart et type
    maps[3].addMobMap(new Ghost({ 500, 40, 32, 28 }));

    //      Map 4
    //  Load Background
    maps[4].setMap(LoadTexture("../CyTechProject/CyTechProject/files/ressources/map/map4.png"));
    //  Platforms
    maps[4].addPlatformMap({ 428, 406, 53*5, 10 });
    a = 534;
    maps[4].addPlatformMap({ a,855,1600 - a,10 });
    maps[4].addPlatformMap({ 213, 270, 53 * 5, 10 });
    maps[4].addPlatformMap({ 639, 136, 53 * 6, 10 });
    //  Boxes
    maps[4].addBoxMap({ 0,540,53*4,44*2 });
    maps[4].addBoxMap({ 215,630,53 * 4,44 * 2 });
    maps[4].addBoxMap({ 427,721,53 * 2,44 * 3 });
    maps[4].addBoxMap({ 856,497,53,44 /2 });
    maps[4].addBoxMap({ 908,475,35,44 / 2 });
    maps[4].addBoxMap({ 942,453,70,44 / 2 });
    maps[4].addBoxMap({ 1015,431,35,44 / 2 });
    maps[4].addBoxMap({ 1050,409,315,44 / 2 });
    maps[4].addBoxMap({ 1367,431,20,44 / 2 });
    maps[4].addBoxMap({ 1388,453,84,44 / 2 });
    maps[4].addBoxMap({ 1474,475,20,44 / 2 });
    maps[4].addBoxMap({ 1494,497,53,44 / 2 });
    //  Mobs depart et type
    maps[4].addMobMap(new Ghost({ 500, 40, 32, 28 }));

    //      Map 5
    //  Load Background
    maps[5].setMap(LoadTexture("../CyTechProject/CyTechProject/files/ressources/map/map5.png"));
    //  Platforms
    maps[5].addPlatformMap({ 0, 180, 53 * 2, 10 });
    maps[5].addPlatformMap({ 0, 315, 53 * 2, 10 });
    maps[5].addPlatformMap({ 53, 450, 480, 10 });
    maps[5].addPlatformMap({ 639, 450, 320, 10 });
    maps[5].addPlatformMap({ 1067, 450, 480, 10 });
    maps[5].addPlatformMap({ 0,855,1600,10 });
    maps[5].addPlatformMap({ 1013, 315, 160, 10 });
    maps[5].addPlatformMap({ 480, 584, 53 * 5, 10 });
    //  Boxes
    maps[5].addBoxMap({ 480,833,54 / 2,44 / 2 });
    maps[5].addBoxMap({ 773, 833, 53 / 2, 44/2 });
    maps[5].addBoxMap({ 507, 810, 266, 44/2 });
    maps[5].addBoxMap({ 536,723,54 * 3,44 * 2 });
    maps[5].addBoxMap({ 694,765,54,44});
    maps[5].addBoxMap({ 1388,766,54*2,44*2 });
    maps[5].addBoxMap({ 1494,722,53*2,44*3 });
    //  Mobs depart et type
    maps[5].addMobMap(new Ghost({ 500, 40, 32, 28 }));


    int indicMap = 1;
    int indicLim = 5;

    std::vector<Mob* >mobC;

    mobC.clear();
    for (unsigned j = 0; j < maps[indicMap].getMobs().size(); j++) {
        mobC.push_back((*maps[indicMap].getMob(j)).copy());
    }

    Camera2D camera = { 0 };
    camera.target = { 800, 450 };
    camera.offset.x = screenWidth / 2.0f;
    camera.offset.y = screenHeight / 2.0f;
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

#pragma region initAnim
    animation_zombie.Init_animation_zombie();
    animation_joueur.Init_animation_joueur();
    animation_ghost.Init_animation_ghost();
    animation_ratKing.Init_animation_ratKing();
    animation_scythe.Init_animation_scythe();
    animation_deathTouch.Init_animation_deathTouch();
#pragma endregion initAnim

    audio.Init();

#pragma endregion initialisation

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

#pragma region MainGameLoop
    while (!WindowShouldClose())
    {
#pragma region Update
        //----------------------------------------------------------------------------------
        float deltaTime = GetFrameTime();

        maps[indicMap].afficheBackground();

        //for (int i = 0; i < maps[indicMap].getPlatforms().size(); i++) DrawRectangleRec(maps[indicMap].getPlatforms()[i].getRectangle(), GRAY);
        //for (int i = 0; i < maps[indicMap].getBoxes().size(); i++) DrawRectangleRec(maps[indicMap].getBoxes()[i].getRectangle(), PURPLE);

        audio.Update(player, arme);
        player.updatePlayer(maps[indicMap].getPlatforms(), maps[indicMap].getBoxes(), deltaTime);

       


        for (int i = 0; i < NB_MOB_PASSIF; i++) {
            if (CheckCollisionRecs(player.getRectangle(), mobPassif[i].getRectangle()) && mobPassif[i].getIsAlive()) {
                mobPassif[i].setIsAlive(false);
            }

            if (mobPassif[i].getIsAlive()) {
                //DrawRectangleRec(mobPassif[i].getRectangle(), GREEN);
            }
        }

        for (unsigned i = 0; i < mobC.size(); i++) {
            if ((CheckCollisionRecs(player.getRectangle(), mobC[i]->getRectangle()) && mobC[i]->getIsAlive()) || IsKeyPressed(KEY_N)) {
                player.setIsAlive(false);
                player.setPersonnage({ 300, 100, 28, 40 });
                if (indicMap == indicLim) {
                    indicMap = 0;
                }
                indicMap += 1;

                mobC.clear();
                for (unsigned j = 0; j < maps[indicMap].getMobs().size(); j++) {
                    mobC.push_back((* maps[indicMap].getMob(j)).copy());
                }

                mobPassif[0].setPersonnage({ 450, 300, 50, 50 });
                mobPassif[1].setPersonnage({ 0, 200, 50, 50 });
                mobPassif[2].setPersonnage({ 300, 600, 50, 50 });
                break;
            }

            if (CheckCollisionRecs(arme.getRectangle(), mobC[i]->getRectangle()) && arme.getActive() > 0 && arme.getEtat()) {
                if (mobC[i]->getIsKillable()) mobC[i]->setIsAlive(false);
            }

            if (CheckCollisionCircleRec(item.getPosition(), item.getRadius(), mobC[i]->getRectangle()) && item.getActive()) {
                if (mobC[i]->getIsKillable()) mobC[i]->setIsAlive(false);
            }

            if (CheckCollisionRecs(deathTouch.getRectangle(), mobC[i]->getRectangle()) && deathTouch.getActive() && mobC[i]->getIsAlive()) {
                if (mobC[i]->getIsKillable()) {
                    mobC[i]->setIsAlive(false);
                    deathTouch.setOut();
                }
            }

            if (mobC[i]->getIsAlive()) {
                mobC[i]->pathMob(player);
                Rectangle tmp = mobC[i]->getRectangle();
                //printf("%d, %s\n", i, mobC[i]->getOrientation() ? "true" : "false");
                //DrawRectangleRec(tmp, RED);
            }
        }

#pragma region UpdateAnimation
        framesCounter++;

        if (framesCounter >= (60 / FRAMES_SPEED))
        {   
            framesCounter = 0;
            currentFrame++;
            currentFrameImmobile++;
            currentFrameAttaque++;
            currentFrameZombie++;
            currentFrameRatKing++;
            currentFrameScythe++;
            currentFrameDeathTouch++;
            
            
            if (currentFrame > 5) currentFrame = 0;
            if (currentFrameImmobile > 6) currentFrameImmobile = 0;
            if (currentFrameAttaque > 6) currentFrameAttaque = 0;
            if (currentFrameZombie > 3) currentFrameZombie = 0;
            if (currentFrameRatKing > 15) currentFrameRatKing = 0;
            if (currentFrameScythe > 7) currentFrameScythe = 0;
            if (currentFrameDeathTouch > 1) currentFrameDeathTouch = 0;
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
        if (item.getActive()) {
            if (item.getDirection()== true)
                animation_scythe.animation_loop_droite({item.getX()- 40, item.getY() - 37}, currentFrameScythe);
            else
                animation_scythe.animation_loop_gauche({item.getX() - 30, item.getY() - 37}, currentFrameScythe);
        }

        if (deathTouch.getActive()) {
            if (deathTouch.getDirection())
                animation_deathTouch.animation_loop_droite(deathTouch.getPosition(), currentFrameDeathTouch);
            else
                animation_deathTouch.animation_loop_gauche(deathTouch.getPosition(), currentFrameDeathTouch);
        }


        for (unsigned i = 0; i < mobC.size(); i++) {
            if (mobC[i]->getIsAlive()) {
                if (mobC[i]->getType() == "ratKing") {
                    if (mobC[i]->getOrientation())
                        animation_ratKing.animation_run_droite(mobC[i]->getPosition(), currentFrameRatKing);
                    else
                        animation_ratKing.animation_run_gauche(mobC[i]->getPosition(), currentFrameRatKing);
                }
                if (mobC[i]->getType() == "ghost") {
                    if (mobC[i]->getOrientation())
                        animation_ghost.animation_run_droite(mobC[i]->getPosition(), currentFrameZombie);
                    else          
                        animation_ghost.animation_run_gauche(mobC[i]->getPosition(), currentFrameZombie);
                }
                if (mobC[i]->getType() == "zombie") {
                    if (mobC[i]->getOrientation())
                        animation_zombie.animation_run_droite(mobC[i]->getPosition(), currentFrameZombie);
                    else
                        animation_zombie.animation_run_gauche(mobC[i]->getPosition(), currentFrameZombie);
                }
            }
        }


#pragma region Joueur
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
#pragma endregion Joueur

        arme.updateArme(player);
        if (item.possetion()) item.updateArme(player);
        else deathTouch.updateArme(player, &maps[indicMap]);

#pragma endregion DrawAnimation

        EndMode2D();

        EndDrawing();
#pragma endregion Draw

    }
#pragma endregion MainGameLoop

    audio.Free();

    CloseWindow();        // Close window and OpenGL context

    //delete mob données
    for (unsigned i = 0; i < mobC.size(); i++) {
        delete mobC[i];
    }
    for (unsigned i = 0; i < 6; i++) {
        maps[i].~Map();
    }


    return 0;
}