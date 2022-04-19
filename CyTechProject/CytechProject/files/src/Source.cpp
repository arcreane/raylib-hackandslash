#include "raylib.h"
#include "raymath.h"
#include "../../Platform.h"
#include "../../Personnage.h"

//JB was here
//Henri is in your wall
#define G 1000
#define PLAYER_JUMP_SPD 550.0f
#define PLAYER_HOR_SPD 500.0f

const int screenWidth = 1600;
const int screenHeight = 900;

class EnvItem {
private:
    int id;
    char* type;
    Rectangle hitBox;
    Color color;
public:
    void setItem(int id, char* type, Rectangle hitBox, Color color) {
        this->id = id;
        this->type = type;
        this->hitBox = hitBox;
        this->color = color;
    }
};


/*typedef struct Platform {
    Rectangle rect;
    Color color;
} Platform;*/


void UpdatePlayer(Personnage player, Platform* platform, float delta);
void CheckCollisionPlatform(Personnage player, Platform* platform);

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Premier test");

    //EnvItem platform;
    //platform.setItem(1, "plat", { 10,10,10,10 }, BLUE);

    Personnage player;
    player.setPersonnage({ 300, 100, 40, 40 }, true, 0, false);

    Platform *platform;
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

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        float deltaTime = GetFrameTime();

        for (int i = 0; i < platformLength; i++) DrawRectangleRec(platform[i].getRectangle(), GRAY);

        UpdatePlayer(player, platform, deltaTime);


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(LIGHTGRAY);

        DrawText("Test", 20, 20, 20, DARKGRAY);

        BeginMode2D(camera);

        Rectangle playerRect = { player.getPosition().x - (float)(player.getDimension().width / 2), player.getPosition().y - (float)player.getDimension().height, (float)player.getDimension().width, (float)player.getDimension().height };
        DrawRectangleRec(playerRect, BLUE);

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

void UpdatePlayer(Personnage player, Platform* platform, float delta)
{
    Dimension dim = player.getDimension();

    if (IsKeyDown(KEY_LEFT)) player.setPosition({ player.getPosition().x - PLAYER_HOR_SPD * delta, player.getPosition().y });
    if (IsKeyDown(KEY_RIGHT)) player.setPosition({ player.getPosition().x + PLAYER_HOR_SPD * delta, player.getPosition().y });
    if (IsKeyDown(KEY_SPACE) && player.getCanJump()) player.setSpeed(player.getSpeed() - PLAYER_JUMP_SPD);

    player.setPosition({ player.getPosition().x, player.getPosition().y + player.getSpeed() * delta });
    player.setSpeed(player.getSpeed() + G * delta);
    player.setCanJump(false);

    if (player.getPosition().y > screenHeight)
    {
        player.setSpeed(0);
        player.setPosition({ player.getPosition().x, screenHeight });
        player.setCanJump(true);
    }

    if (player.getPosition().x < dim.width / 2) player.setPosition({ (float)dim.width / 2, player.getPosition().y });
    if (player.getPosition().x > screenWidth - dim.width / 2) player.setPosition({ (float)screenWidth - (float)dim.width / 2, player.getPosition().y });
    if (player.getPosition().y < dim.height) {
        player.setSpeed(0);
        player.setPosition({ player.getPosition().x, (float)dim.height });
    }

    CheckCollisionPlatform(player, platform);
}

void CheckCollisionPlatform(Personnage player, Platform* platform) {
    for (int i = 0; sizeof(platform); i++) {
        if (player.getX() >= platform[i].getXd() && player.getXDroite() <= platform[i].getXDroite()
            && player.getYBas() <= platform[i].getY() && (player.getYBas() + player.getSpeed()) >= platform[i].getY()) {
            player.setSpeed(0);
            player.setYBas(platform[i].getY());
            player.setCanJump(true);
        }
    }
}