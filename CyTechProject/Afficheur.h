#define MAX_FONTS   8

class Afficheur
{
public:
	void Load();
	void Unload();
	void Print(int i, const char* a, Color color);

private:
	Font fonts[MAX_FONTS] = { 0 };

};
