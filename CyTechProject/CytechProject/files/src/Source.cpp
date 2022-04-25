#include "raylib.h"
#include "raymath.h"
#include "../../Platform.h"
#include "../../Joueur.h"
#include "../../Mob.h"
#include "../../Arme.h"
#include "../../Animation_Joueur.h"

//JB was here
//Henri is in your wall

typedef struct PlayArme {
    Joueur j;
    Arme a;
}PlayArme;

#define G 1000
#define PLAYER_JUMP_SPD 550.0f
#define PLAYER_HOR_SPD 500.0f

const int screenWidth = 1600;
const int screenHeight = 900;


PlayArme UpdatePlayer(Joueur player, Platform platform[9], Arme attaque, float delta);
Joueur CheckCollisionPlatform(Joueur player, Platform platform[9], float delta);

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Premier test");

    Joueur player;
    player.setPersonnage({ 300, 100, 40, 40 });

    Arme arme;
    arme.setArme({ 60, 40 }, 30, 20);

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

    //Test Anim
    Vector2 position = { 350.0f, 280.0f };
    Texture2D fireball = LoadTexture("../CyTechProject/CyTechProject/files/ressources/chaosFireball02.png");
    Rectangle frameRec = { 0.0f, 0.0f, (float)fireball.width, (float)fireball.height };



    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        float deltaTime = GetFrameTime();

        for (int i = 0; i < platformLength; i++) DrawRectangleRec(platform[i].getRectangle(), GRAY);

        PlayArme pa = UpdatePlayer(player, platform, arme, deltaTime);
        player = pa.j;
        arme = pa.a;

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
            if (arme.getActive() > 0) {
                DrawRectangleRec(arme.getRectangle(), YELLOW);
            }
            arme.setCd();
            if (arme.getCd() <= 0) {
                arme.setOff();
            }
        }



        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(LIGHTGRAY);

        DrawText("Test", 20, 20, 20, DARKGRAY);

        //testAnim
        DrawTextureRec(fireball, frameRec, position, LIGHTGRAY);

        BeginMode2D(camera);

        Rectangle playerRect = { player.getPosition().x - (float)(player.getDimension().width / 2), player.getPosition().y - (float)player.getDimension().height, (float)player.getDimension().width, (float)player.getDimension().height };
        DrawRectangleRec(player.getRectangle(), BLUE);

        EndMode2D();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;

}

PlayArme UpdatePlayer(Joueur player, Platform platform[9], Arme arme, float delta)
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
    if (IsKeyDown(KEY_SPACE)) {
        if (player.getOrientation() == true) arme.setOn({ player.getXDroite(), player.getY() });
        else {
            arme.setOn({ player.getX() - arme.getWidth(), player.getY() });
        }
    }

    player.setY(player.getY() + player.getSpeed() * delta);
    player.setSpeed(player.getSpeed() + G * delta);
    player.setCanJump(false);

    if (player.getYBas() > screenHeight)
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

    PlayArme pa;
    pa.j = player;
    pa.a = arme;
    return pa;
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