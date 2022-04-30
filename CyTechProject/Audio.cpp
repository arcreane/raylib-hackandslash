
#include "Audio.h"


void Audio::Init() {
    InitAudioDevice();
    this->music = LoadMusicStream("../CyTechProject/CyTechProject/files/ressources/son/scifi.mp3");
    PlayMusicStream(music);
    SetMusicVolume(this->music, 0.5f);
    this->attack = LoadSound("../CyTechProject/CyTechProject/files/ressources/son/attack.wav");
    this->jump = LoadSound("../CyTechProject/CyTechProject/files/ressources/son/jump.wav");
}

void Audio::Update(Joueur player, ArmeCAC arme) {
    UpdateMusicStream(this->music);
    if (IsKeyDown(KEY_J) && !arme.getEtat())  PlaySoundMulti(this->attack);
    if (IsKeyDown(KEY_UP) && player.getCanJump()) PlaySoundMulti(this->jump);
}

void Audio::Free() {
    StopSoundMulti();
    UnloadSound(this->attack);
    UnloadSound(this->jump);
    UnloadMusicStream(this->music);   
    CloseAudioDevice();        
}
