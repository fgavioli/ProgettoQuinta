#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
//Strutture utilizzate per ogni personaggio su schermo che descrivono posizionamento e caratteristiche principali personaggi.
struct recLocation
{
	int X;
	int Y;
};
struct recPersonaggio
{
	short MoveSpeed;
	short HealthPoints;
	ALLEGRO_BITMAP *Sprite;
	recLocation Location;
	bool Visible = false;
};

recPersonaggio initrecPersonaggio(short MoveSpeed, short HealthPoints, ALLEGRO_BITMAP *Sprite, recLocation Location, bool isVisible);
recLocation initrecLocation(int x, int y);
void move(recPersonaggio &target, int targetX, int targetY);
void reRender();
bool player_action();