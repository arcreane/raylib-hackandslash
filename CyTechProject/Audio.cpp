
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
    this->deathTouch = LoadSound("../CyTechProject/CyTechProject/files/ressources/son/deathTouch.wav");
    this->mortZombie = LoadSound("../CyTechProject/CyTechProject/files/ressources/son/mortZombie.wav");
    this->mortGhost = LoadSound("../CyTechProject/CyTechProject/files/ressources/son/mortGhost.wav");
    this->mortRatKing = LoadSound("../CyTechProject/CyTechProject/files/ressources/son/mortRatKing.wav");
    this->mortJoueur = LoadSound("../CyTechProject/CyTechProject/files/ressources/son/mortJoueur.wav");
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

void Audio::UpdateDeathTouch()
{
    PlaySound(this->deathTouch);
}

void Audio::MortZombie()
{
    PlaySoundMulti(mortZombie);
}

void Audio::MortGhost()
{
    PlaySoundMulti(mortGhost);
}

void Audio::MortRatKing()
{
    PlaySoundMulti(mortRatKing);
}

void Audio::MortJoueur()
{
    PlaySound(mortJoueur);
}

void Audio::Free() {
    StopSoundMulti();
    UnloadSound(this->attack);
    UnloadSound(this->jump);
    UnloadSound(this->portail);
    UnloadSound(this->scythe);
    UnloadSound(this->mortZombie);
    UnloadSound(this->mortGhost);
    UnloadSound(this->mortRatKing);
    UnloadSound(this->mortJoueur);
    UnloadMusicStream(this->music);   

    CloseAudioDevice();        
}
