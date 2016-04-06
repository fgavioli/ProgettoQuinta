#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
//Strutture utilizzate per ogni personaggio su schermo che descrivono posizionamento e caratteristiche principali personaggi.
struct recLocation
{
	int X;
	int Y;
};
struct recStanza{

	ALLEGRO_BITMAP* immagine;
	short rowStanza, colStanza;
	short lim_left, lim_right, lim_up, lim_down; //limiti delle stanze
	short door_left, door_right, door_up, door_down; //porte delle stanze 
};

struct recPersonaggio
{
	short MoveSpeed;
	short HealthPoints;
	short stanza;
	short sourceX = 0;
	short sourceY = 0;
	ALLEGRO_BITMAP *Sprite;
	int AnimationPhase;
	recLocation Location;
	bool Visible = false;
	bool anim = false;
};

recStanza initrecStanza(ALLEGRO_BITMAP *immagine, short num_stanza, short lim_left, short lim_right, short lim_up, short lim_down, short door_left, short door_right, short door_up, short door_down);
recPersonaggio initrecPersonaggio(short MoveSpeed, short HealthPoints, short stanza, ALLEGRO_BITMAP *Sprite, recLocation Location, bool isVisible);
recLocation initrecLocation(int x, int y);
void move(recPersonaggio &target, int targetX, int targetY);
void load_stanze();
void reRender();
bool player_action();
void movCycle();