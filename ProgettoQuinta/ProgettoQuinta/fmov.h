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
	// Dato che la stanza è 1024x768 i limiti superiori e inferiori delle stanze sono a loro volta 
	// 0,0,1024,768
	short door_left, door_right, door_up, door_down; //porte delle stanze 
};

struct recPersonaggio
{
	short MoveSpeed;							//Velocità di movimento del personaggio
	short HealthPointsATM;						//Punti Vita Attuali
	short HealthPointsTOT;						//Punti Vita Totali
	short stanza;								//Probabilmente da togliere
	short faseAnim;								//Valore numerico da 0 a 4 che identifica lo stato dell'animazione
	short dirAnim;								//Direzione verso la quale il personaggio è girato 
	ALLEGRO_BITMAP *Sprite;						//Sprite completo con matrice animazioni personaggio
	recLocation Location;						//Posizione assoluta del personaggio nella mappa
	bool Visible = false;						//Parametro Visible per ogni oggetto personaggio
	bool anim = false;
};

recStanza initrecStanza(ALLEGRO_BITMAP *immagine, short num_stanza, short lim_left, short lim_right, short lim_up, short lim_down, short door_left, short door_right, short door_up, short door_down);
recPersonaggio initrecPersonaggio(short MoveSpeed, short HealthPoints, short stanza, ALLEGRO_BITMAP *Sprite, recLocation Location, bool isVisible);
recLocation initrecLocation(int x, int y);
void load_stanze();
void reRender();
bool player_action();
void movCycle();
void disegna_personaggio();
void control_collisioni(char l);