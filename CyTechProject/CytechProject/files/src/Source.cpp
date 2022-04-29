#include "raylib.h"
#include "raymath.h"
#include "../../Platform.h"
#include "../../mobPath1.h"
#include "../../mobPath2.h"
#include "../../Arme.h"
#include "../../Animation_Joueur.h"
#include "../../Map.h"
#include "../../Animation_Zombie.h"
#include "../../Animation_Ghost.h"
#include "../../Animation_RatKing.h"
#include <vector>
#include <string>


//JB was here
//Henri is in your wall


#define G 1000
#define PLAYER_JUMP_SPD 550.0f
#define PLAYER_HOR_SPD 300.0f
#define FRAMES_SPEED 8
#define NB_MOB_PASSIF 3

const int screenWidth = 1600;
const int screenHeight = 900;
int currentFrame = 0;
int currentFrameImmobile = 0;
int framesCounter = 0;
int currentFrameAttaque = 0;
int currentFrameZombie = 0;
int currentFrameRatKing = 0;

Joueur UpdatePlayer(Joueur player, std::vector<Platform > platform, std::vector<Platform> box, Arme attaque, float delta);
Joueur CheckCollisionPlatform(Joueur player, std::vector<Platform > platform, float delta);
Joueur CheckCollisionBlocPlein(Joueur player, std::vector<Platform> box, float delta);
Arme UpdateArme(Joueur player, Arme arme);


int main(void)
{
    InitWindow(screenWidth, screenHeight, "Premier test");

#pragma region Initialisation

    Animation_RatKing animation_ratKing;
    Animation_Joueur animation_joueur;
    Animation_Zombie animation_zombie;
    Animation_Ghost animation_ghost;

    Joueur player;
    player.setPersonnage({ 300, 100, 28, 40 });

    Arme arme;
    arme.setArme({ 60, 40 }, 100, 35);

    Map maps[5];

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
    maps[1].addMobMap(new MobPath1({ 750, 200, 50, 50 }, true, 700, 800));
    maps[1].addMobMap(new MobPath2({ 500, 40, 50, 50 }));
    maps[1].addMobMap(new MobPath1({ 375, 600, 50, 50 }, true, 300, 450));
    maps[1].addMobMap(new Mob({ 0,855,1600,5 }));

    maps[2].setMap(LoadTexture("../CyTechProject/CyTechProject/files/ressources/map/map2.png"));
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
    maps[2].addPlatformMap({ a, 673, screenWidth - a, 10 });
    maps[2].addPlatformMap({ 800, 810, 54, 10 });
    maps[2].addPlatformMap({ 852, 764, 54, 10 });
    maps[2].addMobMap(new Mob({ 0,855,1600,5 }));
    maps[2].addMobMap(new MobPath2({ 500, 40, 50, 50 }));

    maps[3].setMap(LoadTexture("../CyTechProject/CyTechProject/files/ressources/map/map3.png"));
    maps[3].addPlatformMap({ 0, 180, 317, 10 });
    maps[3].addPlatformMap({ 0,315,531,10 });
    maps[3].addPlatformMap({ 0,448,1013,10 });
    maps[3].addPlatformMap({ 0,855,1600,10 });

    int indicMap = 1;
    int indicLim = 2;

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

        maps[indicMap].afficheBackground();

        for (int i = 0; i < maps[indicMap].getPlatforms().size(); i++) DrawRectangleRec(maps[indicMap].getPlatforms()[i].getRectangle(), GRAY);
        for (int i = 0; i < maps[indicMap].getBoxes().size(); i++) DrawRectangleRec(maps[indicMap].getBoxes()[i].getRectangle(), PURPLE);

        player = UpdatePlayer(player, maps[indicMap].getPlatforms(), maps[indicMap].getBoxes(), arme, deltaTime);

        

        for (int i = 0; i < NB_MOB_PASSIF; i++) {
            if (CheckCollisionRecs(player.getRectangle(), mobPassif[i].getRectangle()) && mobPassif[i].getIsAlive()) {
                mobPassif[i].setIsAlive(false);
            }

            if (mobPassif[i].getIsAlive()) {
                DrawRectangleRec(mobPassif[i].getRectangle(), GREEN);
            }
        }

        for (unsigned i = 0; i < mobC.size(); i++) {
            if (CheckCollisionRecs(player.getRectangle(), mobC[i]->getRectangle()) && mobC[i]->getIsAlive()) {
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
                mobC[i]->setIsAlive(false);
            }

            if (mobC[i]->getIsAlive()) {
                mobC[i]->pathMob(player);
                Rectangle tmp = mobC[i]->getRectangle();
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
            currentFrameAttaque++;
            currentFrameZombie++;
            currentFrameRatKing++;
            
            
            if (currentFrame > 5) currentFrame = 0;
            if (currentFrameImmobile > 6) currentFrameImmobile = 0;
            if (currentFrameAttaque > 6) currentFrameAttaque = 0;
            if (currentFrameZombie > 3) currentFrameZombie = 0;
            if (currentFrameRatKing > 15) currentFrameRatKing = 0;
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

        arme = UpdateArme(player, arme);
#pragma endregion DrawAnimation

        EndMode2D();

        EndDrawing();
#pragma endregion Draw

    }
#pragma endregion MainGameLoop

    CloseWindow();        // Close window and OpenGL context

    //delete mob données
    for (unsigned i = 0; i < mobC.size(); i++) {
        delete mobC[i];
    }


    return 0;
}

Joueur UpdatePlayer(Joueur player, std::vector<Platform> platform, std::vector<Platform> box, Arme arme, float delta)
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
    player = CheckCollisionBlocPlein(player, box, delta);

    return player;
}

Joueur CheckCollisionPlatform(Joueur player, std::vector<Platform> platform, float delta) {
    for (int i = 0; i < platform.size(); i++) {
        if (player.getX() >= platform[i].getXd() - player.getWidth() && player.getXDroite() <= platform[i].getXDroite() + player.getWidth()
            && player.getYBas() <= platform[i].getY() && (player.getYBas() + player.getSpeed() * delta) > platform[i].getY()) {
            player.setSpeed(0);
            player.setYBas(platform[i].getY());
            player.setCanJump(true);
        }
    }
    return player;
}

Joueur CheckCollisionBlocPlein(Joueur player, std::vector<Platform> box, float delta) {
    for (int i = 0; i < box.size(); i++) {
        if (player.getXDroite() > box[i].getXd() && IsKeyDown(KEY_RIGHT) && player.getYBas() > box[i].getY() + 1 + G * delta && player.getY() < box[i].getYBas() - G * delta && player.getX() < box[i].getXDroite() - 1) player.setXDroite(box[i].getXd());
        if (player.getX() < box[i].getXDroite() && IsKeyDown(KEY_LEFT) && player.getYBas() > box[i].getY() + 1 + G * delta && player.getY() < box[i].getYBas() - G * delta && player.getXDroite() > box[i].getXd()) {
            player.setX(box[i].getXDroite());
        }

        if (player.getYBas() >= box[i].getY() && player.getX() < box[i].getXDroite() && player.getXDroite() > box[i].getXd() && player.getY() < box[i].getYBas() - G * delta)
        {
            if (player.getSpeed() >= 0) {
                player.setSpeed(0);
                player.setYBas(box[i].getY());
                player.setCanJump(true);
            }
        }

        if (player.getY() < box[i].getYBas() && player.getX() < box[i].getXDroite() && player.getXDroite() > box[i].getXd() && player.getYBas() > box[i].getY() + 20)
        {
            if (player.getSpeed()) {
                player.setSpeed(0);
                player.setY(box[i].getYBas());
            }
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