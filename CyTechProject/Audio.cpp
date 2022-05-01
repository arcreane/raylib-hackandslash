
#include "Audio.h"


void Audio::Init() {
    InitAudioDevice();
    this->music = LoadMusicStream("../CyTechProject/CyTechProject/files/ressources/son/scifi.mp3");
    PlayMusicStream(music);
    SetMusicVolume(this->music, 0.5f);
    this->attack = LoadSound("../CyTechProject/CyTechProject/files/ressources/son/attack.wav");
    this->jump = LoadSound("../CyTechProject/CyTechProject/files/ressources/son/jump.wav");
    this->portail = LoadSound("../CyTechProject/CyTechProject/files/ressources/son/portail.wav");
    this->scythe = LoadSound("../CyTechProject/CyTechProject/files/ressources/son/scythe.wav");
}

void Audio::Update(Joueur player, ArmeCAC arme) {
    UpdateMusicStream(this->music);
    if (IsKeyDown(KEY_J) && !arme.getEtat())  PlaySoundMulti(this->attack);
    if (IsKeyDown(KEY_UP) && player.getCanJump()) PlaySoundMulti(this->jump);
}

void Audio::UpdatePortail()
{
        UpdateMusicStream(this->music);
        PlaySound(this->portail);
}

void Audio::UpdateAudio()
{
    PlaySoundMulti(this->jump);
}

void Audio::UpdateScythe()
{
    PlaySound(this->scythe);

}

void Audio::Free() {
    StopSoundMulti();
    UnloadSound(this->attack);
    UnloadSound(this->jump);
    UnloadSound(this->portail);
    UnloadSound(this->scythe);
    UnloadMusicStream(this->music);   

    CloseAudioDevice();        
}
