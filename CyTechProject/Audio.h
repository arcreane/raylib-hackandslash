#include "raylib.h"

class Audio
{
public:
	void Init();
	void Update();
	void Free();


private:
	Music music;
	Sound attack;
	Sound jump;
};
