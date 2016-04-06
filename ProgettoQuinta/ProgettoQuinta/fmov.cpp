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
#define E 4
using namespace std;

enum dir{ down=0 ,left=48,right=96,up=128}direction;
bool key_buffer[] { NULL, NULL, NULL, NULL, NULL };
//Dichiarazione di variabili "ambientali" necessarie come base per la visualizzazione, quindi globali.
recPersonaggio target;
recStanza stanza1;
bool redraw = false;
bool anim = false;
const int size = 5;
ALLEGRO_BITMAP* bg[3];
ALLEGRO_BITMAP* bg_copia;
ALLEGRO_BITMAP* sprite;
//funzioni di inizializzazione per maggiore pulizia del codice.
recPersonaggio initrecPersonaggio(short MoveSpeed, short HealthPoints,short stanza, ALLEGRO_BITMAP *Sprite, recLocation Location, bool isVisible){
	recPersonaggio r;
	r.MoveSpeed = MoveSpeed;
	r.HealthPoints = HealthPoints;
	r.Sprite = Sprite;
	r.Location = Location;
	r.Visible = isVisible;
	r.stanza = stanza;
	r.AnimationPhase = 0;
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

//Funzione per le animazioni
void personaggio_img() {

		switch (direction)
		{
		case down:
			target.sourceY = 0;
			if (anim == TRUE){
				target.sourceX += 32;
				anim = FALSE;
			}
			if (target.sourceX != 128)
				al_draw_bitmap_region(target.Sprite, target.sourceX, target.sourceY, 32, 48, target.Location.X, target.Location.Y, NULL);
			else{
				target.sourceX = 0;
				al_draw_bitmap_region(target.Sprite, target.sourceX, target.sourceY, 32, 48, target.Location.X, target.Location.Y, NULL);
			}
			break;
		case up:
			target.sourceY = 144;
			if (anim == TRUE){
				target.sourceX += 32;
				anim = FALSE;
			}
			if (target.sourceX != 128)
				al_draw_bitmap_region(target.Sprite, target.sourceX, target.sourceY, 32, 48, target.Location.X, target.Location.Y, NULL);
			else{
				target.sourceX = 0;
				al_draw_bitmap_region(target.Sprite, target.sourceX, target.sourceY, 32, 48, target.Location.X, target.Location.Y, NULL);
			}
			break;
		case left:
			target.sourceY = 48;
			if (anim == TRUE){
				target.sourceX += 32;
				anim = FALSE;
			}
			if (target.sourceX != 128)
				al_draw_bitmap_region(target.Sprite, target.sourceX, target.sourceY, 32, 48, target.Location.X, target.Location.Y, NULL);
			else{
				target.sourceX = 0;
				al_draw_bitmap_region(target.Sprite, target.sourceX, target.sourceY, 32, 48, target.Location.X, target.Location.Y, NULL);
			}
			break;
		case right:
			target.sourceY = 96;
			if (anim == TRUE) {
				target.sourceX += 32;
				anim = FALSE;
			}
			if (target.sourceX != 128)
				al_draw_bitmap_region(target.Sprite, target.sourceX, target.sourceY, 32, 48, target.Location.X, target.Location.Y, NULL);
			else{
				target.sourceX = 0;
				al_draw_bitmap_region(target.Sprite, target.sourceX, target.sourceY, 32, 48, target.Location.X, target.Location.Y, NULL);
			}
			break;
		default:
			break;
		}
}

void load_img(){
	bg[1] = al_load_bitmap("bg.jpg");
	bg[2] = al_load_bitmap("bg.jpg");
	sprite = al_load_bitmap("12.png");
}
ALLEGRO_BITMAP* load_stanza(short n){
	switch (n){
	case 1:
		bg_copia = bg[1];
		break;
	case 2:
		bg_copia = bg[2];
		break;
	case 3:
		bg_copia = bg[1];
		break;
	case 4:
		bg_copia = bg[2];
		break;
	default:
		break;
	}
	return bg_copia;
}
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
	bg_copia = load_stanza(target.stanza);
	al_draw_bitmap(bg_copia , 0, 0, 1);
	if (target.Sprite != NULL)
		personaggio_img();
		al_flip_display();
}

void movCycle(){
	load_img();
	target = initrecPersonaggio(5, 10, 1 , sprite, initrecLocation(400, 400), true);
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
			else{
				target.Sprite = sprite;
				redraw = true;
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

			case ALLEGRO_KEY_E:
				key_buffer[E] = true;
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

			case ALLEGRO_KEY_E:
				key_buffer[E] = false;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(coda))
			reRender();
	}
}

bool player_action() {
	bool redr = false;
	char col_char = 'sas';
	if (key_buffer[UP])
	{
		
		anim = true;
		direction = up;
		target.Location.Y -= target.MoveSpeed;
		col_char = 'a';
		control_collisioni(col_char);
		redr = true;
		
	}
	if (key_buffer[DOWN])
	{
		anim = true;
		direction = down;
		target.Location.Y += target.MoveSpeed;
		col_char = 'b';
		control_collisioni(col_char);
		redr = true;
	}
	if (key_buffer[LEFT])
	{
		anim = true;
		direction = left;
		target.Location.X -= target.MoveSpeed;
		col_char = 'c';
		control_collisioni(col_char);
		redr = true;
	}
	if (key_buffer[RIGHT])
	{
		anim = true;
		direction = right;
		target.Location.X += target.MoveSpeed;
		col_char = 'd';
		control_collisioni(col_char);
		redr = true;
	}
	if (key_buffer[E])
	{

		redr = true;
	}
	return redr;
}