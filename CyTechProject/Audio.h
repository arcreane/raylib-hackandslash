#include "raylib.h"
#include "Joueur.h"
#include "ArmeCAC.h"
#include "Portail.h"

class Audio
{
public:
	void Init();
	void Update(Joueur player, ArmeCAC arme);
	void UpdatePortail();
	void UpdateAudio();
	void UpdateScythe();
	void Free();


private:
	Music music;
	Sound attack;
	Sound jump;
	Sound portail;
	Sound scythe;
};
