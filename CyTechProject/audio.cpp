#include "raylib.h"
#include "audio.h"


void Audio::Init() {
    InitAudioDevice();
    this->music = LoadMusicStream("../CyTechProject/CyTechProject/files/ressources/son/scifi.mp3");
    PlayMusicStream(music);
    SetMusicVolume(this->music, 0.5f);
    this->attack = LoadSound("../CyTechProject/CyTechProject/files/ressources/son/attack.wav");
    this->jump = LoadSound("../CyTechProject/CyTechProject/files/ressources/son/jump.wav");
}

void Audio::Update() {
    UpdateMusicStream(this->music);
    if (IsKeyPressed(KEY_J))  PlaySoundMulti(this->attack);
    if (IsKeyPressed(KEY_UP)/*&& player.getCanJump()*/) PlaySoundMulti(this->jump);
}

void Audio::Free() {
    StopSoundMulti();
    UnloadSound(this->attack);
    UnloadSound(this->jump);
    UnloadMusicStream(this->music);   
    CloseAudioDevice();        
}
