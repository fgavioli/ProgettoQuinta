#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_color.h>
#include <allegro5\events.h>
#include <allegro5\allegro_primitives.h>
#include "fmov.h"
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
using namespace std;

enum dir{ down=0 ,left=48,right=96,up=128}posizioneSprite;
bool key_buffer[] { NULL, NULL, NULL, NULL};
//Dichiarazione di variabili "ambientali" necessarie come base per la visualizzazione, quindi globali.
recPersonaggio target;
bool redraw = false;
const int size = 5;
recStanza scenario[3][3];

//funzioni di inizializzazione per diverse strutture
recPersonaggio initrecPersonaggio(short MoveSpeed, short HealthPoints,short stanza, ALLEGRO_BITMAP *Sprite, recLocation Location, bool isVisible){
	recPersonaggio r;
	r.MoveSpeed = MoveSpeed;
	r.HealthPointsATM = HealthPoints;
	r.HealthPointsTOT = HealthPoints;
	r.Sprite = Sprite;
	r.Location = Location;
	r.Visible = isVisible;
	r.stanza = stanza;
	return r;
}
recStanza initrecStanza(ALLEGRO_BITMAP *immagine, short righa, short colonna) {
	recStanza stanza;
	stanza.immagine = immagine;
	stanza.colStanza = colonna;
	stanza.rowStanza = righa;

	return stanza;
};
recLocation initrecLocation(int x, int y){
	recLocation r;
	r.X = x;
	r.Y = y;
	return r;
}

void load_stanze(){
	for (short j = 0; j < 3; j++)
		for (short k = 0; k < 3; k++)
			scenario[j][k] = initrecStanza(al_load_bitmap("bg.png"), j, k);
	//aggiungere load da disco di altre immagini stanze
}
//Funzione per le animazioni (DA GUARDARE!!!!!!!!!!!!)
void disegna_personaggio() {
	recLocation xy = numToLoc(target);
	al_draw_bitmap_region(target.Sprite, xy.X, xy.Y, 32, 48, target.Location.X, target.Location.Y, NULL);
}
//DA GENERALIZZARE UTILIZZANDO STRUTTURA RECSTANZA
void control_collisioni(char l){
	switch (l){
		case 'a': //up
			if (target.Location.Y == 90)
				if (target.Location.X <= 500 && target.Location.X >= 470){
					target.stanza++;
					target.Location.Y = 550;
				}
			else
				target.Location.Y += 5;
			break;
		case 'b': //down
			if (target.Location.Y == 620)
				if (target.Location.X <= 700 && target.Location.X >= 570){
					target.stanza--;
					target.Location.Y = 100;
				}
			else
				target.Location.Y -= 5;
			break;
		case 'c': //left
			if (target.Location.X == 100){
				if (target.Location.Y <= 380 && target.Location.Y >= 270){
					target.stanza++;
					target.Location.X = 990;
				}
				else
					target.Location.X += 5;
			}
			break;
		case 'd': //right
			if (target.Location.X >= 890){
				if (target.Location.Y <= 380 && target.Location.Y >= 270){
					target.stanza--;
					target.Location.X = 250;
				}
				else
					target.Location.X -= 5;
			}
			break;
		default:
		break;
	}
}
//Funzione che cancella ogni oggetto su schermo e lo ridisegna se il parametro visible dell'oggetto stesso è true.
void reRender(){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(scenario[0][0].immagine , 0, 0, 1);
	disegna_personaggio();
	al_flip_display();
}

void movCycle(){
	load_stanze();
	target = initrecPersonaggio(5, 10, 1, al_load_bitmap("12.png"), initrecLocation(400, 400), true);
	ALLEGRO_EVENT_QUEUE *coda = NULL;
	ALLEGRO_TIMER* timer;
	coda = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
	al_register_event_source(coda, al_get_timer_event_source(timer));
	al_register_event_source(coda, al_get_keyboard_event_source());
	al_start_timer(timer);
	int animationFrameCounter = 0;
	while (!false)
	{
		ALLEGRO_EVENT e;
		al_wait_for_event(coda, &e);
		if (e.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = player_action();
			animationFrameCounter++;
			if (animationFrameCounter > 60)
				animationFrameCounter = 0;
		}
		else if (e.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (e.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
				key_buffer[UP] = true;
				break;

			case ALLEGRO_KEY_S:
				key_buffer[DOWN] = true;
				break;

			case ALLEGRO_KEY_A:
				key_buffer[LEFT] = true;
				break;

			case ALLEGRO_KEY_D:
				key_buffer[RIGHT] = true;
				break;
			}
		}

		else if (e.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (e.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
				key_buffer[UP] = false;
				break;

			case ALLEGRO_KEY_S:
				key_buffer[DOWN] = false;
				break;

			case ALLEGRO_KEY_A:
				key_buffer[LEFT] = false;
				break;

			case ALLEGRO_KEY_D:
				key_buffer[RIGHT] = false;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(coda))
			reRender();
	}
}
//DA GUARDARE
bool player_action() {
	bool redr = false;
	char col_char = '0';
	if (key_buffer[UP])
	{
		target.anim = true;
		target.dirAnim = 0;
		target.Location.Y -= target.MoveSpeed;
		col_char = 'a';
		control_collisioni(col_char);
		redr = true;
		
	}
	if (key_buffer[DOWN])
	{
		target.anim = true;
		target.dirAnim = 1;
		target.Location.Y += target.MoveSpeed;
		col_char = 'b';
		control_collisioni(col_char);
		redr = true;
	}
	if (key_buffer[LEFT])
	{
		target.anim = true;
		target.dirAnim = 2;
		target.Location.X -= target.MoveSpeed;
		col_char = 'c';
		control_collisioni(col_char);
		redr = true;
	}
	if (key_buffer[RIGHT])
	{
		target.anim = true;
		target.dirAnim = 3;
		target.Location.X += target.MoveSpeed;
		col_char = 'd';
		control_collisioni(col_char);
		redr = true;
	}
	return redr;
}

recLocation numToLoc(recPersonaggio p){
	recLocation loc = initrecLocation(-1, -1);
	switch (p.faseAnim)
	{
	case 0:
		loc.X = 0;
		break;
	case 1:
		loc.X = 32;
		break;
	case 2:
		loc.X = 64;
		break;
	case 3:
		loc.X = 96;
		break;
	}
	switch (p.dirAnim)
	{
	case 0:
		loc.Y = 0;
		break;
	case 1:
		loc.Y = 48;
		break;
	case 2:
		loc.Y = 96;
		break;
	case 3:
		loc.Y = 144;
		break;
	}
	return loc;
}