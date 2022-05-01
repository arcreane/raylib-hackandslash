#include "raylib.h"
#include "raymath.h"
#include "../../Joueur.h"
#include "../../Platform.h"
#include "../../ArmeCAC.h"
#include "../../ArmeDistance.h"
#include "../../DeathTouch.h"
#include "../../Portail.h"
#include "../../RatKing.h"
#include "../../Zombie.h"
#include "../../Ghost.h"
#include "../../Lave.h"
#include "../../Arme.h"
#include "../../Portail.h"
#include "../../Animation_Joueur.h"
#include "../../Map.h"
#include "../../Animation_Zombie.h"
#include "../../Animation_Ghost.h"
#include "../../Animation_RatKing.h"
#include "../../Animation_Scythe.h"
#include "../../Animation_DeathTouch.h"
#include "../../Animation_Portail.h"
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
int currentFramePortail = 1;
bool afficherPortail = false;

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Jeu Vid�o GAMING");

#pragma region Initialisation

    Animation_RatKing animation_ratKing;
    Animation_Joueur animation_joueur;
    Animation_Zombie animation_zombie;
    Animation_Ghost animation_ghost;
    Animation_Scythe animation_scythe;
    Animation_DeathTouch animation_deathTouch;
    Animation_Portail animation_portail;

    Audio audio;

    Joueur player;


    ArmeCAC arme;
    arme.setArme({ 60, 40 }, 70, 35);
    ArmeDistance scythe;
    scythe.setArme(34);
    DeathTouch deathTouch;
    deathTouch.setArme();



    Map maps[6];

    Mob mobPassif[NB_MOB_PASSIF];
    mobPassif[0].setPersonnage({ 450, 300, 50, 50 });
    mobPassif[1].setPersonnage({ 0, 200, 50, 50 });
    mobPassif[2].setPersonnage({ 300, 600, 50, 50 });


    //      Map 1
    //  Load Background
    maps[1].setMap(LoadTexture("../CyTechProject/CyTechProject/files/ressources/map/map1.png"));
    //  Spawn
    maps[1].setSpawn({ 140, 365, 28, 40 });
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
    maps[1].addPlatformMap({ a, 628, (screenWidth - a), 10 });
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
    //maps[1].addMobMap(new RatKing({ 750, 200, 33, 48 }, true, 700, 800));
    //maps[1].addMobMap(new Ghost({ 500, 40, 32, 28 }));
    //maps[1].addMobMap(new Ghost({ 1100, 715, 32, 28 }));
    //maps[1].addMobMap(new Ghost({ 1550, 480, 32, 28 }));
    maps[1].addMobMap(new RatKing({ 375, 600, 33, 48 }, true, 300, 450));
    maps[1].addMobMap(new Lave({ 0,855,1600,5 }));
    maps[1].addMobMap(new Zombie({ 577 ,1, 34, 40 }, true, &maps[1]));
    maps[1].addMobMap(new Zombie({ 1300, 60, 34,40 }, true, &maps[1]));
    maps[1].addMobMap(new Zombie({ 1150, 360, 34, 40 }, true, &maps[1]));
    maps[1].addMobMap(new Zombie({ 1400, 595, 34, 40 }, true, &maps[1]));
    maps[1].addMobMap(new Zombie({ 600, 640, 34, 40 }, true, &maps[1]));

    maps[1].addItemMap(new Portail({ 143,530,50,50 }, "portail"));
    maps[1].addItemMap(new Portail({ 500,360,50,50 }, "deathTouch"));
    maps[1].addItemMap(new Portail({ 500,360,50,50 }, "scythe"));

    //      Map 2
    //  Load Background
    maps[2].setMap(LoadTexture("../CyTechProject/CyTechProject/files/ressources/map/map2.png"));
    //  Spawn
    maps[2].setSpawn({ 1400, 650, 28, 40 });
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
    maps[2].addMobMap(new Ghost({ 500, 40, 32, 28 }));
    maps[2].addMobMap(new Ghost({ 1280, 120, 32, 28 }));
    maps[2].addMobMap(new Ghost({ 530, 720, 32, 28 }));
    maps[2].addMobMap(new RatKing({ 455, 36, 33, 48 }, true, 430, 550));
    maps[2].addMobMap(new RatKing({ 1250, 150 , 33, 48 }, true, 1100, 1350));
    maps[2].addMobMap(new Zombie({ 55, 90, 34,40 }, true, & maps[2]));
    maps[2].addMobMap(new Zombie({ 55, 230, 34, 40 }, true, & maps[2]));
    maps[2].addMobMap(new Zombie({ 300,815,34,40 }, true, & maps[2]));
    maps[2].addMobMap(new Zombie({ 450,815,34,40 }, true, & maps[2]));

    maps[2].addItemMap(new Portail({1430,220,50,50}, "portail"));

    //      Map 3
    //  Load Background
    maps[3].setMap(LoadTexture("../CyTechProject/CyTechProject/files/ressources/map/map3.png"));
    //  Spawn
    maps[3].setSpawn({ 1100, 815, 28, 40 });
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
    maps[3].addMobMap(new Ghost({ 40, 40, 32, 28 }));
    maps[3].addMobMap(new Ghost({ 830, 300, 32, 28 }));
    maps[3].addMobMap(new Ghost({ 1500, 80, 32, 28 }));
    maps[3].addMobMap(new Ghost({ 1400, 740, 32, 28 }));
    maps[3].addMobMap(new RatKing({ 80, 550, 33, 48 }, true, 70, 400));
    maps[3].addMobMap(new RatKing({ 1085, 65 , 33, 48 }, true, 1000, 1550));
    maps[3].addMobMap(new Zombie({ 30, 120, 34,40 }, true, & maps[3]));
    maps[3].addMobMap(new Zombie({ 60, 410, 34, 40 }, true, & maps[3]));
    maps[3].addMobMap(new Zombie({ 645,665 ,34,40 }, true, & maps[3]));
    maps[3].addMobMap(new Zombie({ 520,90 ,34 ,40 }, true, & maps[3]));

    maps[3].addItemMap(new Portail({ 1090,85,50,50 }, "portail"));

    //      Map 4
    //  Load Background
    maps[4].setMap(LoadTexture("../CyTechProject/CyTechProject/files/ressources/map/map4.png"));
    //  Spawn
    maps[4].setSpawn({ 1180, 375, 28, 40 });
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
    maps[4].addMobMap(new Ghost({ 100, 100, 32, 28 }));
    maps[4].addMobMap(new Ghost({ 80, 800, 32, 28 }));
    maps[4].addMobMap(new Ghost({ 1500, 600, 32, 28 }));
    maps[4].addMobMap(new RatKing({ 1200, 50, 33, 48 }, true, 1100, 1550));
    maps[4].addMobMap(new RatKing({ 1100, 610, 33, 48 }, true, 990, 1400));
    maps[4].addMobMap(new RatKing({ 1300, 280 , 33, 48 }, true, 950, 1500));
    maps[4].addMobMap(new Zombie({ 600, 805, 34,40 }, true, & maps[4]));
    maps[4].addMobMap(new Zombie({ 460, 360, 34, 40 }, true, & maps[4]));
    maps[4].addMobMap(new Zombie({ 700, 100 ,34,40 }, true, & maps[4]));
    maps[4].addMobMap(new Zombie({ 245, 220, 34 ,40 }, true, & maps[4]));

    maps[4].addItemMap(new Portail({ 1175,790,50,50 }, "portail"));

    //      Map 5
    //  Load Background
    maps[5].setMap(LoadTexture("../CyTechProject/CyTechProject/files/ressources/map/map5.png"));
    //  Spawn
    maps[5].setSpawn({ 1050, 815, 28, 40 });
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
    maps[5].addMobMap(new Ghost({ 50, 50, 32, 28 }));
    maps[5].addMobMap(new Ghost({ 500, 50, 32, 28 }));
    maps[5].addMobMap(new Ghost({ 1000, 50, 32, 28 }));
    maps[5].addMobMap(new Ghost({ 1450, 50, 32, 28 }));
    maps[5].addMobMap(new Ghost({ 1500, 300, 32, 28 }));
    maps[5].addMobMap(new Ghost({ 1550, 650, 32, 28 }));
    maps[5].addMobMap(new RatKing({ 920, 735, 33, 48 }, true, 840, 1300));
    maps[5].addMobMap(new RatKing({ 175, 740, 33, 48 }, true, 50, 420));
    maps[5].addMobMap(new RatKing({ 750, 175 , 33, 48 }, true, 50, 1500));
    maps[5].addMobMap(new Zombie({ 15, 140, 34,40 }, true, & maps[5]));
    maps[5].addMobMap(new Zombie({ 15, 280, 34, 40 }, true, & maps[5]));
    maps[5].addMobMap(new Zombie({ 90, 415 ,34,40 }, true, & maps[5]));
    maps[5].addMobMap(new Zombie({ 680, 415, 34 ,40 }, true, & maps[5]));
    maps[5].addMobMap(new Zombie({ 1100, 415, 34 ,40 }, true, & maps[5]));
    maps[5].addMobMap(new Zombie({ 1030, 275, 34 ,40 }, true, & maps[5]));
    maps[5].addMobMap(new Zombie({ 500, 545, 34 ,40 }, true, & maps[5]));

    maps[5].addItemMap(new Portail({870,200,50,50 }, "portail"));


    player.setPersonnage(maps[1].getSpawn());

    int indicMap = 1;
    int indicLim = 5;

    std::vector<Mob* >mobC;
    std::vector<Item* >itemC;

    mobC.clear();
    for (unsigned j = 0; j < maps[indicMap].getMobs().size(); j++) {
        mobC.push_back((*maps[indicMap].getMob(j)).copy());
    }

    itemC.clear();
    for (unsigned k = 0; k < maps[indicMap].getItems().size(); k++) {
        itemC.push_back((*maps[indicMap].getItem(k)).copy());
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
    animation_portail.Init_animation_portail();
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

        for (unsigned i = 0; i < itemC.size(); i++) {
            if (CheckCollisionRecs(player.getRectangle(), itemC[i]->getRectangle()) || IsKeyPressed(KEY_N)) {
                if ((itemC[i]->getType() == "portail" && afficherPortail) || IsKeyPressed(KEY_N)) {
                    if (indicMap == indicLim) {
                        indicMap = 0;
                    }
                    indicMap += 1;

                    player.setPersonnage(maps[indicMap].getSpawn());

                    itemC.clear();
                    for (unsigned j = 0; j < maps[indicMap].getItems().size(); j++) {
                        itemC.push_back((*maps[indicMap].getItem(j)).copy());
                    }
                    mobC.clear();
                    for (unsigned j = 0; j < maps[indicMap].getMobs().size(); j++) {
                        mobC.push_back((*maps[indicMap].getMob(j)).copy());
                    }
                    audio.UpdatePortail();

                    //mobPassif[0].setPersonnage({ 450, 300, 50, 50 });
                    //mobPassif[1].setPersonnage({ 0, 200, 50, 50 });
                    //mobPassif[2].setPersonnage({ 300, 600, 50, 50 });
                    break;
                }

                if (itemC[i]->getType() == "scythe" && IsKeyPressed(KEY_H) && !scythe.possetion()) {
                    deathTouch.setPossetion(false);
                    scythe.setPossetion(true);
                }
                if (itemC[i]->getType() == "deathTouch" && IsKeyPressed(KEY_K) && !deathTouch.possetion()) {
                    scythe.setPossetion(false);
                    deathTouch.setPossetion(true);
                    //DrawRectangleRec({ 0,0,20,20 }, PINK);
                }
            }
        }

        DrawRectangleRec({ 500,360,50,50 }, PINK);

        afficherPortail = true;

        for (unsigned i = 0; i < mobC.size(); i++) {            
            if ((CheckCollisionRecs(player.getRectangle(), mobC[i]->getRectangle()) && mobC[i]->getIsAlive()))  {
                player.setIsAlive(false);
                player.setPersonnage(maps[indicMap].getSpawn());

                mobC.clear();
                for (unsigned j = 0; j < maps[indicMap].getMobs().size(); j++) {
                    mobC.push_back((*maps[indicMap].getMob(j)).copy());
                }

                //mobPassif[0].setPersonnage({ 450, 300, 50, 50 });
                //mobPassif[1].setPersonnage({ 0, 200, 50, 50 });
                //mobPassif[2].setPersonnage({ 300, 600, 50, 50 });
                break;
            }

            if (CheckCollisionRecs(arme.getRectangle(), mobC[i]->getRectangle()) && arme.getActive() > 0 && arme.getEtat()) {
                if (mobC[i]->getIsKillable()) mobC[i]->setIsAlive(false);
            }

            if (CheckCollisionCircleRec(scythe.getPosition(), scythe.getRadius(), mobC[i]->getRectangle()) && scythe.getActive()) {
                if (mobC[i]->getIsKillable()) mobC[i]->setIsAlive(false);
            }

            if (CheckCollisionRecs(deathTouch.getRectangle(), mobC[i]->getRectangle()) && deathTouch.getActive() && mobC[i]->getIsAlive()) {
                if (mobC[i]->getIsKillable()) {
                    mobC[i]->setIsAlive(false);
                    deathTouch.setOut();
                }
            }

            if (mobC[i]->getIsAlive()) {
                if (mobC[i]->getIsKillable()) {
                    mobC[i]->pathMob(player);
                    afficherPortail = false;

                }
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
            currentFramePortail++;
            
            
            if (currentFrame > 5) currentFrame = 0;
            if (currentFrameImmobile > 6) currentFrameImmobile = 0;
            if (currentFrameAttaque > 6) currentFrameAttaque = 0;
            if (currentFrameZombie > 3) currentFrameZombie = 0;
            if (currentFrameRatKing > 15) currentFrameRatKing = 0;
            if (currentFrameScythe > 7) currentFrameScythe = 0;
            if (currentFrameDeathTouch > 1) currentFrameDeathTouch = 0;
            if (currentFramePortail > 150) currentFramePortail = 1;
        }
#pragma endregion UpdateAnimation

#pragma endregion Update

#pragma region Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(LIGHTGRAY);


        DrawText("Utilisez les fleches directionnelles pour vous deplacer",20,65, 20, BLACK);
        DrawText("Appuyez sur J pour Attaquer", 20, 40, 20, BLACK);
        DrawText("Appuyez sur Y pour utiliser votre objet", 20, 90, 20, BLACK);
        



        BeginMode2D(camera);

        Rectangle playerRect = { player.getPosition().x - (float)(player.getDimension().width / 2), player.getPosition().y - (float)player.getDimension().height, (float)player.getDimension().width, (float)player.getDimension().height };
        


#pragma region DrawAnimation
        if (scythe.getActive()) {
            if (scythe.getDirection()== true)
                animation_scythe.animation_loop_droite({scythe.getX()- 40, scythe.getY() - 37}, currentFrameScythe);
            else
                animation_scythe.animation_loop_gauche({scythe.getX() - 30, scythe.getY() - 37}, currentFrameScythe);
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

        for (unsigned i = 0; i < itemC.size(); i++) {
            if (itemC[i]->getType() == "portail" && afficherPortail) {
                animation_portail.animation_portail({ itemC[i]->getX() - 25, itemC[i]->getY() - 25 }, currentFramePortail);
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
        if (scythe.possetion()) scythe.updateArme(player);
        else deathTouch.updateArme(player, &maps[indicMap]);

#pragma endregion DrawAnimation

        EndMode2D();

        EndDrawing();
#pragma endregion Draw

    }
#pragma endregion MainGameLoop

    audio.Free();

    CloseWindow();        // Close window and OpenGL context

    //delete mob donn�es
    for (unsigned i = 0; i < mobC.size(); i++) {
        delete mobC[i];
    }
    for (unsigned i = 0; i < 6; i++) {
        maps[i].~Map();
    }


    return 0;
}