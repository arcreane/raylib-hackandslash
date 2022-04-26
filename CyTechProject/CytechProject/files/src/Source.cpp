#include "raylib.h"
#include "raymath.h"
#include "../../Platform.h"
#include "../../Joueur.h"
#include "../../Mob.h"
#include "../../Arme.h"
#include "../../Animation_Joueur.h"

//JB was here
//Henri is in your wall


#define G 1000
#define PLAYER_JUMP_SPD 550.0f
#define PLAYER_HOR_SPD 500.0f
#define FRAMES_SPEED 8

const int screenWidth = 1600;
const int screenHeight = 900;
int currentFrame = 0;
int currentFrameImmobile = 0;
int framesCounter = 0;


Joueur UpdatePlayer(Joueur player, Platform platform[9], Arme attaque, float delta);
Joueur CheckCollisionPlatform(Joueur player, Platform platform[9], float delta);
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

    Mob mob[3];
    mob[0].setPersonnage({ 750, 200, 50, 50 });
    mob[1].setPersonnage({ 500, 40, 50, 50 });
    mob[2].setPersonnage({ 375, 600, 50, 50 });

    Mob mobPassif[3];
    mobPassif[0].setPersonnage({ 450, 300, 50, 50 });
    mobPassif[1].setPersonnage({ 0, 200, 50, 50 });
    mobPassif[2].setPersonnage({ 300, 600, 50, 50 });


    Platform platform[9];
    platform[0].setPlatform({300, 350, 200, 10});
    platform[1].setPlatform({0,250,250,10});
    platform[2].setPlatform({550,250,250,10});
    platform[3].setPlatform({100,150,50,10});
    platform[4].setPlatform({650,150,50,10});
    platform[5].setPlatform({500,90,150,10});
    platform[6].setPlatform({ 300, 500, 200, 10 });
    platform[7].setPlatform({ 300, 650, 200, 10 });
    platform[8].setPlatform({ 300, 800, 200, 10 });


    int platformLength = sizeof(platform) / sizeof(platform)[0];

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

        for (int i = 0; i < platformLength; i++) DrawRectangleRec(platform[i].getRectangle(), GRAY);

        player = UpdatePlayer(player, platform, arme, deltaTime);

        arme = UpdateArme(player, arme);

        for (int i = 0; i < 3; i++) {
            if (CheckCollisionRecs(player.getRectangle(), mobPassif[i].getRectangle()) && mobPassif[i].getIsAlive()) {
                mobPassif[i].setIsAlive(false);
            }

            if (mobPassif[i].getIsAlive()) {
                DrawRectangleRec(mobPassif[i].getRectangle(), GREEN);
            }
        }

        for (int i = 0; i < 3; i++) {
            if (CheckCollisionRecs(player.getRectangle(), mob[i].getRectangle()) && mob[i].getIsAlive()) {
                player.setIsAlive(false);
                player.setPersonnage({ 300, 100, 40, 40 });

                mob[0].setPersonnage({ 750, 200, 50, 50 });
                mob[1].setPersonnage({ 500, 40, 50, 50 });
                mob[2].setPersonnage({ 375, 600, 50, 50 });

                mobPassif[0].setPersonnage({ 450, 300, 50, 50 });
                mobPassif[1].setPersonnage({ 0, 200, 50, 50 });
                mobPassif[2].setPersonnage({ 300, 600, 50, 50 });
            }

            if (CheckCollisionRecs(arme.getRectangle(), mob[i].getRectangle()) && arme.getEtat()) {
                mob[i].setIsAlive(false);
            }

            if (mob[i].getIsAlive()) {
                DrawRectangleRec(mob[i].getRectangle(), RED);
            }
        }

        if (arme.getEtat() == true) {
            if (arme.getDirection() == true) {
                arme.setOn({ player.getXDroite(), player.getY() });
            }
            else {
                arme.setOn({ player.getX() - arme.getWidth(), player.getY() });
            }
            if (arme.getActive() > 0) {
                DrawRectangleRec(arme.getRectangle(), YELLOW);
            }
            arme.setCd();
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

            if (currentFrame > 5) currentFrame = 0;
            if (currentFrameImmobile > 6) currentFrameImmobile = 0;
        }
#pragma endregion UpdateAnimation

#pragma endregion Update

#pragma region Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(LIGHTGRAY);

        DrawText("Test", 20, 20, 20, DARKGRAY);



        BeginMode2D(camera);

        Rectangle playerRect = { player.getPosition().x - (float)(player.getDimension().width / 2), player.getPosition().y - (float)player.getDimension().height, (float)player.getDimension().width, (float)player.getDimension().height };
        


#pragma region DrawAnimation

        if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT) && !(player.getCanJump())) animation_joueur.animation_jump_droite(player.getPosition(), currentFrameImmobile);
        if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT) && !(player.getCanJump())) animation_joueur.animation_jump_gauche(player.getPosition(), currentFrameImmobile);
        if (((!IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT)) || ((IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_LEFT)))) && player.getOrientation()) animation_joueur.animation_immobile_droite(player.getPosition(), currentFrameImmobile);
        if (((!IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT)) || ((IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_LEFT)))) && !(player.getOrientation())) animation_joueur.animation_immobile_gauche(player.getPosition(), currentFrameImmobile);
        if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT) && player.getCanJump()) animation_joueur.animation_run_droite(player.getPosition(), currentFrame);
        if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT) && player.getCanJump()) animation_joueur.animation_run_gauche(player.getPosition(), currentFrame);

#pragma endregion DrawAnimation

        EndMode2D();

        EndDrawing();
#pragma endregion Draw 
    }
#pragma endregion MainGameLoop

    CloseWindow();        // Close window and OpenGL context


    return 0;

}

Joueur UpdatePlayer(Joueur player, Platform platform[9], Arme arme, float delta)
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

Joueur CheckCollisionPlatform(Joueur player, Platform platform[9], float delta) {
    for (int i = 0; i <= sizeof(platform); i++) {
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