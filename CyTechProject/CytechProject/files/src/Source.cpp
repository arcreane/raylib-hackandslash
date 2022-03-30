#include "raylib.h"
#include "raymath.h"
//#include "Personnage.h"
//JB was here
#define G 1000
#define PLAYER_JUMP_SPD 550.0f
#define PLAYER_HOR_SPD 500.0f

const int screenWidth = 800;
const int screenHeight = 450;

typedef struct Dimension {
    int width;
    int height;
}Dimension;

class Personnage {
private:
    Vector2 position;
    bool orientation;
    float speed;
    bool canJump;
    Dimension dimension;
public:
    void setPersonnage(Vector2 p, bool o, float s, bool cj, Dimension d) {
        this->position = p;
        this->orientation = o;
        this->speed = s;
        this->canJump = cj;
        this->dimension = d;
    }
    void setPosition(Vector2 p) {
        this->position = p;
    }
    void setOrientation(bool b) {
        this->orientation = b;
    }
    void setSpeed(float s) {
        this->speed = s;
    }
    void setCanJump(bool cj) {
        this->canJump = cj;
    }

    Vector2 getPosition() {
        return this->position;
    }
    bool getOrientation() {
        return this->orientation;
    }
    float getSpeed() {
        return this->speed;
    }
    bool getCanJump() {
        return this->canJump;
    }
    Dimension getDimension() {
        return this->dimension;
    }

    //void seDeplacer();
};

typedef struct Player {
    Vector2 position;
    float speed;
    bool canJump;
    int width;
    int high;
    Color color;
} Player;

class EnvItem {
private:
    char type;
    Rectangle hitBox;
    Color color;
};

class Platforms : EnvItem {

};

typedef struct Platform {
    Rectangle rect;
    Color color;
} Platform;


Personnage UpdatePlayer(Personnage player, Platform* platform, float delta);
Personnage verifPlatform(Personnage player, Platform* platform, float delta);

int main(void)
{

    InitWindow(screenWidth, screenHeight, "Premier test");

    Personnage player;
    player.setPersonnage({ 300, 100 }, true, 0, false, { 100, 40 });

    Platform platform[] = {
        {{300,350,200,10}, BLUE},
        {{0,250,250,10}, GRAY},
        {{550,250,250,10}, GRAY},
        {{100,150,50,10}, GRAY},
        {{650,150,50,10}, GRAY},
        {{500,90,150,10}, RED}
    };

    int platformLength = sizeof(platform) / sizeof(platform)[0];

    Camera2D camera = { 0 };
    camera.target = { 400, 225 };
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

        for (int i = 0; i < platformLength; i++) DrawRectangleRec(platform[i].rect, platform[i].color);

        player = UpdatePlayer(player, platform, deltaTime);


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

Personnage UpdatePlayer(Personnage player, Platform* platform, float delta)
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

    player = verifPlatform(player, platform, delta);

    return player;
}

Personnage verifPlatform(Personnage player, Platform* platform, float delta)
{
    float px = player.getPosition().x;
    float py = player.getPosition().y;
    float speed = player.getSpeed();
    Dimension dim = player.getDimension();

    for (int i = 0; i < sizeof(platform); i++)
    { 
        Platform* plat = platform + i;
        if (px >= plat->rect.x - dim.width / 2 &&
            px <= plat->rect.x + plat->rect.width + dim.width / 2 &&
            py <= plat->rect.y &&
            py + speed * delta > plat->rect.y)
        {
            player.setPosition({ px, plat->rect.y });
            player.setSpeed(0);
            player.setCanJump(true);
        }
    }

    return player;
}