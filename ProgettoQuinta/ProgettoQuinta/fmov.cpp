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
recStanza initrecStanza(ALLEGRO_BITMAP *immagine, short num_stanza, short col_left, short col_right, short col_up, short col_down, short door_left, short door_right, short door_up, short door_down){
	recStanza stanza;
	stanza.immagine = immagine;
	//stanza.num_stanza = num_stanza;
	stanza.door_left = door_left;
	stanza.door_right = door_right;
	stanza.door_up = door_up;
	stanza.door_down = door_down;
	return stanza;
};
recLocation initrecLocation(int x, int y){
	recLocation r;
	r.X = x;
	r.Y = y;
	return r;
}

void load_stanze(){
	scenario[0][0].immagine = al_load_bitmap("bg.png");
	//aggiungere load da disco di altre immagini stanze
}
//Funzione per le animazioni (DA GUARDARE!!!!!!!!!!!!)
void disegna_personaggio() {

		switch (posizioneSprite)
		{
		case down:
			target.faseAnim = 0;
			if (target.anim == TRUE){
				target.dirAnim += 32;
				target.anim = FALSE;
			}
			if (target.dirAnim != 128)
				al_draw_bitmap_region(target.Sprite, target.dirAnim, target.faseAnim, 32, 48, target.Location.X, target.Location.Y, NULL);
			else{
				target.dirAnim = 0;
				al_draw_bitmap_region(target.Sprite, target.dirAnim, target.faseAnim, 32, 48, target.Location.X, target.Location.Y, NULL);
			}
			break;
		case up:
			target.faseAnim = 144;
			if (target.anim == TRUE){
				target.dirAnim += 32;
				target.anim = FALSE;
			}
			if (target.dirAnim != 128)
				al_draw_bitmap_region(target.Sprite, target.dirAnim, target.faseAnim, 32, 48, target.Location.X, target.Location.Y, NULL);
			else{
				target.dirAnim = 0;
				al_draw_bitmap_region(target.Sprite, target.dirAnim, target.faseAnim, 32, 48, target.Location.X, target.Location.Y, NULL);
			}
			break;
		case left:
			target.faseAnim = 48;
			if (target.anim == TRUE){
				target.dirAnim += 32;
				target.anim = FALSE;
			}
			if (target.dirAnim != 128)
				al_draw_bitmap_region(target.Sprite, target.dirAnim, target.faseAnim, 32, 48, target.Location.X, target.Location.Y, NULL);
			else{
				target.dirAnim = 0;
				al_draw_bitmap_region(target.Sprite, target.dirAnim, target.faseAnim, 32, 48, target.Location.X, target.Location.Y, NULL);
			}
			break;
		case right:
			target.faseAnim = 96;
			if (target.anim == TRUE) {
				target.dirAnim += 32;
				target.anim = FALSE;
			}
			if (target.dirAnim != 128)
				al_draw_bitmap_region(target.Sprite, target.dirAnim, target.faseAnim, 32, 48, target.Location.X, target.Location.Y, NULL);
			else{
				target.dirAnim = 0;
				al_draw_bitmap_region(target.Sprite, target.dirAnim, target.faseAnim, 32, 48, target.Location.X, target.Location.Y, NULL);
			}
			break;
		default:
			break;
		}
}
//DA GENERALIZZARE UTILIZZANDO STRUTTURA RECSTANZA
void control_collisioni(char l){
	switch (l){
		case 'a': //up
			if (target.Location.Y == 60)
				if (target.Location.X <= 700 && target.Location.X >= 570){
					target.stanza++;
					target.Location.Y = 550;
				}
			else
				target.Location.Y += 5;
			break;
		case 'b': //down
			if (target.Location.Y == 580)
				if (target.Location.X <= 700 && target.Location.X >= 570){
					target.stanza--;
					target.Location.Y = 100;
				}
			else
				target.Location.Y -= 5;
			break;
		case 'c': //left
			if (target.Location.X == 240){
				if (target.Location.Y <= 380 && target.Location.Y >= 270){
					target.stanza++;
					target.Location.X = 990;
				}
				else
					target.Location.X += 5;
			}
			break;
		case 'd': //right
			if (target.Location.X >= 990){
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
			if (redraw){
				animationFrameCounter++;
				if (animationFrameCounter > 0){

					animationFrameCounter = 0;
				}
			}
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
		posizioneSprite = up;
		target.Location.Y -= target.MoveSpeed;
		col_char = 'a';
		control_collisioni(col_char);
		redr = true;
		
	}
	if (key_buffer[DOWN])
	{
		target.anim = true;
		posizioneSprite = down;
		target.Location.Y += target.MoveSpeed;
		col_char = 'b';
		control_collisioni(col_char);
		redr = true;
	}
	if (key_buffer[LEFT])
	{
		target.anim = true;
		posizioneSprite = left;
		target.Location.X -= target.MoveSpeed;
		col_char = 'c';
		control_collisioni(col_char);
		redr = true;
	}
	if (key_buffer[RIGHT])
	{
		target.anim = true;
		posizioneSprite = right;
		target.Location.X += target.MoveSpeed;
		col_char = 'd';
		control_collisioni(col_char);
		redr = true;
	}
	return redr;
}