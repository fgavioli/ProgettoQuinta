#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

#define dx false;
#define giu true;

//Strutture utilizzate per ogni personaggio su schermo che descrivono posizionamento e caratteristiche principali personaggi.
struct recLocation
{
	int X;
	int Y;
};
struct recPorta{
	short larghezza;							//Larghezza della apertura
	recLocation posizione;						//Posizione della porta
	bool direzione;								//Indica la direzione verso cui la porta verra disegnata(renderizzata)
};
struct recStanza{

	ALLEGRO_BITMAP* immagine;
	recPorta porte[];
	short rowStanza, colStanza;

	// Dato che la stanza è 1024x768 i limiti superiori e inferiori delle stanze sono a loro volta 
	// 0,0,1024,768
	
};

struct recPersonaggio
{
	short MoveSpeed;							//Velocità di movimento del personaggio
	short HealthPointsATM;						//Punti Vita Attuali
	short HealthPointsTOT;						//Punti Vita Totali
	short stanza;								//Probabilmente da togliere
	short faseAnim;								//Valore numerico da 0 a 4 che identifica lo stato dell'animazione
	short dirAnim;								//Direzione verso la quale il personaggio è girato 0 - su, 1 - giu, 2 - sx, 3 - dx
	ALLEGRO_BITMAP *Sprite;						//Sprite completo con matrice animazioni personaggio
	recLocation Location;						//Posizione assoluta del personaggio nella mappa
	bool Visible = false;						//Parametro Visible per ogni oggetto personaggio
	bool anim = false;
};

recStanza initrecStanza(ALLEGRO_BITMAP *immagine, short righa, short colonna);
recPersonaggio initrecPersonaggio(short MoveSpeed, short HealthPoints, short stanza, ALLEGRO_BITMAP *Sprite, recLocation Location, bool isVisible);
recLocation initrecLocation(int x, int y);
void load_stanze();
void reRender();
bool player_action();
void movCycle();
void disegna_personaggio();
void control_collisioni(char l);
recLocation numToLoc(recPersonaggio p);