#include "raylib.h"
#include "Afficheur.h"

Vector2 vector = {100.0f,100.0f};

// NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
void Afficheur::Load() {
	this->fonts[0] = LoadFont("resources/fonts/alagard.png");
	this->fonts[1] = LoadFont("resources/fonts/pixelplay.png");
	this->fonts[2] = LoadFont("resources/fonts/mecha.png");
	this->fonts[3] = LoadFont("resources/fonts/setback.png");
	this->fonts[4] = LoadFont("resources/fonts/romulus.png");
	this->fonts[5] = LoadFont("resources/fonts/pixantiqua.png");
	this->fonts[6] = LoadFont("resources/fonts/alpha_beta.png");
	this->fonts[7] = LoadFont("resources/fonts/jupiter_crash.png");
}

void Afficheur::Unload() {
	for (int i = 0; i < MAX_FONTS; i++) UnloadFont(this->fonts[i]);
}

void Afficheur::Print(int i, const char* a,Color color) {
	DrawTextEx(this->fonts[i], a, vector, 20, 20, color);
}

